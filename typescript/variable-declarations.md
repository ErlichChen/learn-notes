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

## let declarations