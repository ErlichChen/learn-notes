# Variable Declarations

## var declarations

```ts
// Declare a variable traditionally in JavaScript
var a = 10;

// Declare a variable inside of a function
function f() {
  var message = "test";
  return message;
}

// Access those same variables within other function
function f() {
  var a = 10;
  return function g() {
    var b = a + 1;
    return b;
  }
}
var g = f();
g(); // returns '11'
```

```ts
function f() {
  var a = 1;
  a = 2;
  // g captured the variable a declared in f.
  // g gets called, the value of a will be tied to the value of a in f.
  var b = g();
  a = 3;

  return b;
  function g() {
    return a;
  }
}
f(); // returns '2'
```

### Scopling rules

```ts
function f(shouldInitialize: boolean) {
	if (shouldInitailize) {
		var x = 0;
	}
	return x;
}
f(true);  // '10'
f(false); // 'undefined'
```

```ts
function sumMaxtrix(matrix: number[]) {
  var sum = 0;
	for (var i = 0; i < matrix.length; i++) {
		var currentRow = matrix[i];
		for (var i = 0;  i < currentRow.length; i++) {
			sum += currentRow[i];
		}
	}
	return sum;
}
```

#### Variable capturing

```ts

for (var i = 0; i < 10; i++) {
  setTimeout(function() { console.log(i); }, 100 * i);
}

for (var i = 0; i < 10; i++) {
  var f = function(i) { console.log(i); }
  setTimeout(f(i), 100 * i);
}

for (var i = 0; i < 10; i++) {
  (function(i) { setTimeout(function() { console.log(i); }, 100 * i); })(i);
}
```

## let declarations

### Block-scoping

A variable is declared using let, it uses what some call lexial-scoping or block-scoping.

```ts
function f(input: boolean) {
    let a = 100;

    if (input) {
        // Still okay to reference 'a'
        let b = a + 1;
        return b;
    }

    // Error: 'b' doesn't exist here
    return b;
}
```

### Re-declarations and Shadowing

```ts
function f(condition, x) {
    if (condition) {
        let x = 100;
        return x;
    }

    return x;
}

f(false, 0); // returns '0'
f(true, 0);  // returns '100'
```

### Block-scoped variable capturing

Each time a scope is run, it creates an "environment" of variables. That environment and its captured variables can exist even after everything within its scope has finished executing.

```ts
for (let i = 0; i < 10 ; i++) {
    setTimeout(function() { console.log(i); }, 100 * i);
}
```

## const declarations