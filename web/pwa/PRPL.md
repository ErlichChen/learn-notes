# The PRPL pattern

PRPL stands for:

* **Push** critical resources for the initial URL route.
* **Render** initial route.
* **Pre-cache** remaining routes.
* **Lazy-load** create remaining routes on demand.

PRPL strives to optimize for:

* Minimum time-to-interactive
* Maximum caching efficiency, especially over time as updates are released.
* Simplicity of development and deployment.

## App structure

PRRL can work well with the single-page app (SPA) structure:

* The main entrypoint of the application which is served from every valid route. The file should be very small, it will be served from different URLs and therefore be cached multiple times. All resource URLs in the entrypoint need to be absolute, since it may be served from non-top-level URLs.
* The shell or app-shell, which includes the top-level app logic router, and so on.
* Lazily loaded fragments of the app. A fragment can represent the code for a particular view, or other code that can be loaded lazily. The shell is responsible for dynamically importing the fragments as needed.

The server and service worker together work to precache the resources for the inactive routes.

![App structure](https://raw.githubusercontent.com/ErlichChen/learning-notes/master/web/pwa/prpl-app-structure.png)

### App entrypoint

* Has minimal static dependencies, in other words, not much beyond the app-shell itself.
* Conditionally loads required polyfills.
* Uses absolute paths for all dependencies.

### App shell

The shell is responsible for routing and usually includes the main navigation UI for the app.
The app should lazy-load fragments as they're required.

## Build output

Your build process could produce two builds:

* An unbundled build designed for server/browsers combinations that support HTTP/2 to deliver the resources the browser needs for a fast first paint while optimizing caching. The delivery of these resources can be triggered efficiently using **<link rel="preload">** or HTTP/2 Push.
* A bundled build designed to minimize the number of round-trips required to get the application running on server/browser combinations that don't support server push.

Your server logic should deliver the appropriate build for each browser.

### Bundled build

For browsers that don't handle HTTP/2, the build process could produce a set of different buildles: one bundle for the shell, and one bundle for each fragment. The diagram below shows how a simple app would be bundled, again using components.

![App bundle](https://raw.githubusercontent.com/ErlichChen/learning-notes/master/web/pwa/prpl-app-bundle.png)

Any dependency shared by two or more fragments is bundled with the shell and its static dependencies.

Each fragment and its unshared static dependencies are bundled into a single bundle. The server should return the approprate version of the fragment(bundled or unbundled), depending on the browser. The means that the shell code can lazy-load detail-view.html without having to know whether it is bundle or unbundled. It relies on the server and browser to load the dependencies in the most efficinent way.

## HTTP/2 and HTTP/2 server push

**HTTP/2** allows mutiplexed downloads over a single connection, so that multiple small files can be downloaded more efficiently.

**HTTP/2 server push** allows the server to preemptively send resources to the browser.

For an example of how HTTP/2 server push speeds up downloads, consider how the browser retrieves an HTML file with a linked stylesheet.

In HTTP/1:

* The browser requests the HTML file.
* The server returns the HTML file and the browser starts parsing it.
* The browser encounters the <link rel="stylesheet"> tag, and starts a new request for the stylesheet.
* The browser receives the stylesheet.

In HTTP/2 push:

* The browser requests the HTML file.
* The server returns the HTML file, and pushes the stylesheet at the same time.
* The browser starts parsing the HTML. By the time it encounters the <link rel="stylesheet">, the stylesheet is already in the cache.

