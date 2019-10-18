# Removing jQuery from Github.com frontend
[](https://github.blog/2018-09-06-removing-jquery-from-github-frontend/)

We were able to achieve everything that we needed using standard browser APIs.

## Why jQuery made sense early on

GitHub pulled in jQuery 1.2.1 as a dependency in late 2017. For a bit of context, that was a year before Google released the first version of their Chrome browser. There was no standard way to query DOM elements by a CSS selector, no standard way to animate visual styles of an element, and the XMLHttpRequest interface pioneered by internet explorer was, like many other APIs, inconsistent between browsers.

jQuery made it simple to manipulate the DOM, define animations, and make “AJAX” requests— basically, it enabled web developers to create more modern, dynamic experiences that stood out from the rest. Most importantly of all, the JavaScript features built in one browser with jQuery would generally work in other browsers, too. In those early days of GitHub when most of its features were still getting fleshed out, this allowed the small development team to prototype rapidly and get new features out the door without having to adjust code specifically for each web browser.

## Web standards in the later years

When it came to jQuery, we compared it against the rapid evolution of supported web standard in modern browsers and realized:

The $(selector) pattern can easily be replaced with querySelectorAll();
CSS classname switching can now be achieved using Element.classList;
CSS now supports defining visual animations in stylesheets rather than in JavaScript;
$.ajax requests can be performed using the Fetch Standard;
The addEventListener() interface is stable enough for cross-platform use;
We could easily encapsulate the event delegation pattern with a lightweight library;
Some syntactic sugar that jQuery provides has become reduntant with the evolution of JavaScript language.

Furthermore, the chaining syntax didn’t satisfy how we wanted to write code going forward. For example:

```js
$('.js-widget')
  .addClass('is-loading')
  .show()
```

This syntax is simple to write, but to our standards, doesn’t communicate intent really well. Did the author expect one or more js-widget elements on this page? Also, if we update our page markup and accidentally leave out the js-widget classname, will an exception in the browser inform us that something went wrong? By default, jQuery silently skips the whole expresion when nothing matched the initial selector; but to us, such behavior was a bug rather than a feature.

Finally, we wanted to start annotating types with Flow to perform static type checking at build time, and we concluded that the chaining syntax doesn’t lend itself well to static analysis, since almost every result of a jQuery method call is of the same type. We chose Flow over alternatives because, at the time, features such as @flow weak mode allowed us to progressively and efficiently start applying types to a codebase which was largely untyped.

All in all, decoupling from jQuery would mean that we could rely on web standards more, have MDN web docs be de-facto default documentation for our frontend developers, maintain more resilient code in the future, and eventually drop a 30 kB dependency from our packaged bundles, speeding up page load times and JavaScript execution times.

## Incremental decoupling

Even with an end goal in sight, we knew that it wouldn’t be feasible to just allocate all resources we had to rewriting everything from jQuery to vanilla JS. If anything, such a rushed endeavor would likely lead to many regressions in site functionality that we would later have to weed out. Instead, we:

Set up metrics that tracked ratio of jQuery calls used per overall line of code and monitored that graph over time to make sure that it’s either staying constant or going down, not up.Graph of jQuery usage going down over time.

We discouraged importing jQuery in any new code. To facilitate that using automation, we created eslint-plugin-jquery which would fail CI checks if anyone tried to use jQuery features, for example $.ajax.
There were now plenty of violations of eslint rules in old code, all of which we’ve annotated with specific eslint-disable rules in code comments. To the reader of that code, those comments would serve as a clear signal that this code doesn’t represent our current coding practices.

We created a pull request bot that would leave a review comment on a pull request pinging our team whenever somebody tried to add a new eslint-disable rule. This way we would get involved in code review early and suggest alternatives.

A lot of old code had explicit coupling to external interfaces of pjax and facebox jQuery plugins, so we’ve kept their interfaces relatively the same while we’ve internally replaced their implementation with vanilla JS. Having static type checking helped us have greater confidence around those refactorings.

Plenty of old code interfaced with rails-behaviors, our adapter for the Ruby on Rails approach to “unobtrusive” JS, in a way that they would attach an AJAX lifecycle handler to certain forms:

```js
// LEGACY APPROACH
$(document).on('ajaxSuccess', 'form.js-widget', function(event, xhr, settings, data) {
  // insert response data somewhere into the DOM
})
```

Instead of having to rewrite all of those call sites at once to the new approach, we’ve opted to trigger fake ajax* lifecycle events and keep these forms submitting their contents asynchronously as before; only this time fetch() was used internally.

We maintained a custom build of jQuery and whenever we’ve identified that we’re not using a certain module of jQuery anymore, we would remove it from the custom build and ship a slimmer version. For instance, after we have removed the final usage of jQuery-specific CSS pseudo-selectors such as :visible or :checkbox, we were able to remove the Sizzle module; and when the last ```$.ajax``` call was replaced with fetch(), we were able to remove the AJAX module. This served a dual purpose: speeding up JavaScript execution times while at the same time ensuring that no new code is created that would try using the removed functionality.

We kept dropping support for old Internet Explorer versions as soon as it would be feasible to, as informed by our site analytics. Whenever use of a certain IE version dropped below a certain threshold, we would stop serving JavaScript to it and focus on testing against and supporting more modern browsers. Dropping support for IE 8–9 early on allowed us to adopt many native browser features that would otherwise be hard to polyfill.
As part of our refined approach to building frontend features on GitHub.com, we focused on getting away with regular HTML foundation as much as we could, and only adding JavaScript behaviors as progressive enhancement. As a result, even those web forms and other UI elements that were enhanced using JS would usually also work with JavaScript disabled in the browser. In some cases, we were able to delete certain legacy behaviors altogether instead of having to rewrite them in vanilla JS.

With these and similar efforts combined over the years, we were able gradually reduce our dependence on jQuery until there was not a single line of code referencing it anymore.

## Custom Elements

One technology that has been making waves in the recent years is Custom Elements: a component library native to the browser, which means that there are no additional bytes of a framework for the user to download, parse and compile.

We had created a few Custom Elements based on the v0 specification since 2014. However, as standards were still in flux back then, we did not invest as much. It was not until 2017 when the Web Components v1 spec was released and implemented in both Chrome and Safari that we began to adopt Custom Elements on a wider scale.

During the jQuery migration, we looked for patterns that would be suitable for extraction as custom elements. For example, we converted our facebox usage for displaying modal dialogs to the <details-dialog> element.

Our general philosophy of striving for progressive enhancement extends to custom elements as well. This means that we keep as much of the content in markup as possible and only add behaviors on top of that. For example, <local-time> shows the raw timestamp by default and gets upgraded to translate the time to the local timezone, while <details-dialog>, when nested in the <details> element, is interactive even without JavaScript, but gets upgraded with accessibility enhancements.

Here is an example of how a <local-time> custom element could be implemented:

```js
// The local-time element displays time in the user's current timezone
// and locale.
//
// Example:
//   <local-time datetime="2018-09-06T08:22:49Z">Sep 6, 2018</local-time>
//
class LocalTimeElement extends HTMLElement {
  static get observedAttributes() {
    return ['datetime']
  }

  attributeChangedCallback(attrName, oldValue, newValue) {
    if (attrName === 'datetime') {
      const date = new Date(newValue)
      this.textContent = date.toLocaleString()
    }
  }
}

if (!window.customElements.get('local-time')) {
  window.LocalTimeElement = LocalTimeElement
  window.customElements.define('local-time', LocalTimeElement)
}
```

One aspect of Web Components that we’re looking forward to adopting is Shadow DOM. The powerful nature of Shadow DOM has the potential to unlock a lot of possibilities for the web, but that also makes it harder to polyfill. Because polyfilling it today incurs a performance penalty even for code that manipulates parts of the DOM unrelated to web components, it is unfeasible for us to start using it in production.

