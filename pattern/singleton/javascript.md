# Singleton

## 单例的基本结构

```js
/* Basic Singleton. */
var Singleton = {
  attribute1: true,
  attribute2: 10,

  method1: function(){ }
  method2: function(arg){ }
}
Singleton.attribute1 = false;
var total = Singleton.attribute2 + 5;
var result = Singleton.method1();
```

单体对象可以被修改，也可以用delete运算符删除成员。违背了面向对象设计的原则，类可以被扩展，但不应该被修改。

单体是一个用来划分命名空间并讲一批相关方法和属性组织在一起的对象，只能被实例化一次。

## 划分命名空间

单体对象:

方法和属性成员的对象本身
属性成员
在JavaScript中，这样声明，容易被后面的改写。

```js
/* Declared globally */
function findProduct(id) { }

// Later in your page, another programmer adds...
var resetProduct = $('reset-product-button');
var findProduct  = $('find-prodcut-buton'); // The findProduct function just got
                                            // overwritten
```

为了避免无意中改写变量，可以用单体对象将代码组织在命名空间之中。

```js
/* Using a namespace. */
var MyNamespace = {
  findProduct: function(id){ },
  // Other methods can go here as well.
}

// Later in your page, another programmer adds...
var resetProduct = $('rest-product-button');
var findProduct = $('find-product-button'); // Nothiing was overwitten.
```

定义一个用来包含自己的所有代码的全局对象。

```js
/* GiantCorp namespace. */
var GiantCorp = {};

GiantCorp.Common = {
  // A singleton with common methods used by all object and modules.
}

GiantCorp.ErrorCodes = {
  // An object Iiteral used to store data.
}

GiantCorp.PageHandler = {
  // A singleton with page specific methods and attributes.
}
```

## 用作特定网页专用代码的包装器的单体

在多种网页的网站中，有些JavaScript代码是所有网页都要用到的，它们通常被存放在独立的文件中，而有些代码则是某个网页专用的，不会被用到其他地方。

```js
/* Generic Page Object. */
Namespace.PageName = {
  // Page constants.
  CONSTANT_1: true,
  CONSTANT_2: 10,

  // Page methods.
  method1: function(){ },
  method2: function(){ },

  // Initializtion method.
  init: function(){ }
}

// Invoke the initialization method after the page loads.
addLoadEvent(Namespace.PageName.init);
GiantCorp.RegPage = {

  // Constants.
  FROM_ID: 'reg-form',
  OUTPUT_ID: 'reg-results',

  // Form handling methods.
  handleSubmit: function(e) {
    e.preventDefault(); // Stop the normal from submission.
    var data = { };
    var inputs = GiantCorp.RegPage.formEl.getElementByTagName('input');

    // Collect the values of the input fields in the form.
    for(var i = 0; len = inputs.length; i < len; i++) {
      data[inputs[i].name] = inputs[i].value;
    }

    // Send the form values back to the server.
    GiantCorp.RegPage.sendRegistration(data);
  },
  sendRegistration: function(data) {
    // Make an XHR request and call displayResult() when the response
    // received.
  },
  displayResult: function(response) {
    // Output the response directly into the output element. We are assuming the server will send back formatted HTML.
    GiantCorp.RegPage.outputEl.innerHTML = response;
  }

  // Initailization method.
  init: function() {
    // Get the form and output elements.
    GiantCorp.RegPage.formEl = $(GiantCorp.RegPage.FORM_ID);

    // Hi jack the form submission.
    addEvent(GiantCorp.RegPage.formEl, 'submit', GiantCorp.RegPage.handleSubmit);
  }
};

// Invoke the inintialization method after the page loads.
addLoadEvent(GiantCorp.RegPage.init);
```

使用的逻辑"或"运算符可以在未找到一个属性时为其提供一个默认值。

```js
var GiantCorp = window.GiantCorp || {};
```
拥有私有成员的单例

使用私有方法创建对象的一个缺点是在于它们比较消耗内存，因为每个实例都具有方法的一份新副本。

使用下划线表示法

在单体对象内创建私有成员最简单的是使用下划线表示法。

```js
/* DataParser singleton, converts character delimited strings into arrays. */
GiantCorp.DataParser = {

  // Private methods.
  _stripWhitespace: function(str){
    return str.replace(/\s+/, '');
  },
  _stringSplict: function(str, delimiter){
    return str.split(delimiter);
  }

  // Public method.
  stringToArray:function(str, delimiter, stringWS){
    if(stringWS){
      str = this._stripWhitespace(str);
    }
    var outputArray = this._stringSplit(str, delimiter);
    return outputArray;
  }
};
```

## 使用闭包

```js
/* Singleton as an Object Literal. */
MyNamespace.Singleton = {};
在定义之后立即执行的函数创建单体。

/* Singleton with Private Members, step 1. */
MyNamespace.Singleton = function(){
  return {};
}();
```

也可以在那个匿名函数定义之外再套上一对圆括号，以表示它会在声明之后立即执行。

```js
/* Singleton with Private MEmebers, step 2. */
MyNamespace.Single = (function(){
  return { // Public members.
    publicAttribute1: true,
    publicAttribute2: 10,

    publicMethod1: function(){ },
    publicMethod2: function(){ },
  };
})();
```
包装函数创建一个可以用来添加真正的私用成员的闭包。任何声明在这个匿名函数中的变量或函数都只能被在同一个闭包中声明的其他函数访问。这种单体模式又称模块模式(module pattern)，因为它可以把一批相关的方法和属性组织为模块并起到划分命名空间的作用。

```js
/* Single with Private Members, step 3. */
MyNamespace.Singleton = (function(){
  // Private members.
  var privateAttribute1 = false;
  var privateAttribute2 = [1, 2, 3];

  publicMethod1: function(){ };
  publicMethod2: function(){ };

  return { // Public members.
    publicAttribute1: true,
    publicAttribute2: 10,

    publicMethod1: function(){ },
    publicMethod2: function(args){ },
  };
})();
```

相比于下划线方法，把私有成员放到闭包中可以确保其不会在单体对象之外被使用。

```js
/* DataParser singleton, converts character delimited strings into arrays */
/* Now using true private methods. */
GiantCorp.DataParser = (function(){
  // Private attributes.
  var whitespaceRegex = /\s+/;

  // Private methods
  function stripwhitespace(str){
    return str.replace(whitespaceRegex, '');
  }
  function stringSplit(str, delimiter){
    return str.split(delimmiter);
  }

  // Everything returned in the object literal is public , but can access the members in the closure created above.
  return {
    // Public method.
    stringToArray: function(str, delimiter, stripWS){
      if(stripWS){
        str = stripWhitespace(str);
      }
      var outputArray = stringSplit(str, delimiter);
      return outputArray;
    }
  }

})();
// Invoke the function and assign the returned object literal to GiantCorp.DataParser.
```

惰性实例化

对于资源密集型的或配置开销大的单体，可以将其实例化推迟到需要使用的时候(lazy loading)

```js
MyNamespace.Singleton.publishMethod1();

MyNamespace.Singleton.getInstance().publishMethod1();
MyNamespace.Singleton = (function(){
  // Private members.
  var privateAttribute1 = false;
  var privateAttribute2 = [1, 2, 3];

  function privateMethod1(){ }
  function privateMethod2(args){ }

  return { // Public members.
    publicAttribute1: true,
    publicAttribute2: 10,

    publicMethod1: function(){ }
    publicMethod2: function(args){ }
  }
})();
```

第一步是把单体的所有代码转移到一个名为constructor的方法中。

```js
/* General skeleton for a lazy loading singleton, step 1. */
MyNamespace.Singleton = (function(){
  function constructor(){ // All of the normal singleton code goes here.
    var privateAttribute1 = false;
    var privateAttribute2 = [1, 2, 3];

    function privateMethod1(){ }
    function privateMethod2(args){ }

    return { // Public members
      publicAttribute1: true,
      publicAttribute2: 10,

      publicMethod1: function(){ },
      publicMethod2: function(args){ }
    }
  }
})();
```

第二步使用公共方法getInstance来开放调用权限。

```js
/* General skeleton for a lazy loading singleton, step 2. */
MyNamespace.Singleton = (function(){
  function constructor(){ }

  return {
    getInstance: function(){ }
  }
});
```

第三步检测类是否已实例化，如果实例化，返回该实例。

```js
/* General skeleton for a lazy loading singleton, step 3. */
Mynamespace.Singleton = (function() {
  var uniqueInstance;   // Private attribute that holds the single instance.
  function constructor() { } // All of the normal singleton code goes here.

  return {
    getInstance: function() {
      if(!uniqueInstance) {
        uniqueInstance = constructor();
      }
      return uniqueInstance;
    }
  }
})
```

## 分支

把浏览器间的差异封装到在运行期间进行设置的动态方法中的技术。

```js
MyNamespace.Singleton = (function() {
  var objectA = {
    method1: function() { },
    method2: function() { },
  };
  var objectB = {
    method1: function() { },
    method2: function() { },
  }
  return (someCondition) ? objectA : objectB;
})();
```

用分支技术创建XHR对象

```js
/* SimleXhrFactory singleton, step 1. */
var SimpleXhrFactory = (function() {
  // The three branches.
  var standard = {
    createXhrObject: function() {
      return new XMLHttpRequest();
    }
  };
  var activeXNew = {
    createXhrObject: function() {
      return new ActiveXObject('Msxml2.XMLHTTP');
    }
  };
  var activeXOld = {
    createXhrObject: function() {
      return new ActiveXObject('Microsoft.XMLHTTP');
    }
  };

  // To assign the branch, try each method; reutrn whatever doesn't fail
  var testObject;
  try {
    testObject = standard.createXhrObject();
    return standard; // Return this if no error was thrown.
  }
  catch(e) {
    try {
      testObject = activeXNew.createXhrObject();
      return activeXNew; // Return this if no error was thrown.
    }
    catch(e) {
      try {
        testObject = activeXOld.createXhrObject();
        return activeXOld; // Return this if no error was thrown.
      }
      catch(e) {
        throw new Error('No XHR object found in this environment.');
      }
    }
  }
});
```