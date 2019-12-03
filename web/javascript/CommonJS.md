
## CommonJS

CommonJS is a style you may be familar with if you're written anything in Node(which uses a slight variant). It's also been gaining traction on the frontend with Browserify.

Using the same format as before, here's what our foo module looks like in CommonJS:

```js
// filename: foo.js
// dependencies
var $ = require('jqurey');

// methods
function myFunc(){};

// exposed public method(single)
module.exports = myFunc;
```

And our more complicate example, with multiple dependencies and multiple exposed methods

```js
// filename: foo.js
var $ = require('jquery');
var _ = require('underscore');

// methods
function a(){}; // private because it's omitted from module.exports
function b(){}; // public because it's defined in module.exports
function c(){}; // public because it's defined in module.exports

// exposed public methods
module.exports = {
  b: b,
  c: c
}
```