# Functions

Dart is a true object-oriented language, so even functions are objects and have a type, Function.

```dart
bool isNoble(int atomicNumber) {
  return _nobleGases[atomicNumber] != null;
}

// shorthand
// The => expr syntax is a shorthand for { return expr; }
bool isNoble(int atmocNumber) => _nobleGases[atomicNumber] != null;
```

## Optional parameters

### Optional named parameters

```dart
// calling a function
enableFlags(bold: true, hidden: false);

// defining a function
void enableFlags({bool bold, bool hidden}) { }

// @required to indicate that it is a required
// Required is defined in the meta package or material package
// package:meta/meta.dart
// package:flutter/material.dart
const Scrollbar({Key key, @required Widget child})
```

### Optional positional parameters

```dart
String say(String from, String msg, [String device]) {
  var result = '$from says $msg';
  if (device != null) {
    result = '$result with a $device';
  }
  return result;
}

assert(say('Bob', 'Howdy') == 'Bob says Howdy');
assert(say('Bob', 'Howdy', 'smoke signal') == 'Bob says Howdy with a smoke signal');
```

### Default parameter values

User = to define default values for both named and positional parameters. The default values must be compile-time contants.

```dart
void enableFlages({ bool bold = false, bool hidden = false }) { }

// bold will be true; hidden will be false.
enableFlages(bold: true);
```

Set default values for positional parameters

```dart
String say(String from, String msg, [String device = 'test', String mood]) {
	var result = '$from says $msg';
	if (device != null) {
		result = '$result with a $device';
	}
	if (mood != null) {
		result = '$result (in a $mood mood)';
	}
	return result;
}

assert(say('A', 'B') == 'A says B with a test');
```

Pass lists or maps as default values.

```dart
void doStuff({
	List<int> list = const [1, 2, 3],
	Map<String, String> map = const [
		"key1": "value1",
		"key2": "value2",
		"key3": "value3",
	]
}) {
	print('list:  $list');
  print('gifts: $map');
}
```

## The main() function

The top-level main() funtion, it serve as the entrypoint to the app. The main() function returns void and has an optional List<String> parameter for arguments.

```dart
// run the app like this: dart args.dart 1 test
void main(List<String> arguments) {
  print(arguments);

  assert(arguments.length == 2);
  assert(int.parse(arguments[0]) == 1);
  assert(arguments[1] == 'test');
}
```

## Function as first-class objects

pass a function as a parameter to another function.

```dart
void printElement(int element) {
	print(element);
}

var list = [1, 2, 3];

// Pass printElement as a parameter.
list.forEach(printElement);
```

Assign a function to a variable.

```dart
var loudify = (msg) => '!!! ${msg.toUpperCase()} !!!';
assert(loudify('hello') == '!!! HELLO !!!');
```

## Anonymous functions

```dart
var list = ['test1', 'test2', 'test3'];
list.forEach((item){
	print('${list.indexOf(item)}: $item');
})

// shorten function
list.forEach((item) => print('${list.indexOf(item)}: $item'));
```

## Lexical scope

Dart is a lexically scoped language, which means that the scope of variables is determined statically, simply by the layout of the code. You can “follow the curly braces outwards” to see if a variable is in scope.

```dart
bool topLevel = true;

void main() {
  var insideMain = true;

  void myFunction() {
    var insideFunction = true;

    void nestedFunction() {
      var insideNestedFunction = true;

      assert(topLevel);
      assert(insideMain);
      assert(insideFunction);
      assert(insideNestedFunction);
    }
  }
}
```

## Lexical closures

A closure is a function objeect that has access to variables in its lexical scope, even when the function is used outside of its original scope.
Functions can close variables defined in surrounding scopes. In the following example, makeAdder() captures the variable addBy. Wherever the returned function goes, it remembers addBy.

```dart
Function makeAdder(num addBy) {
	return (num i) => addBy + i;
}

void main() {
	// Create a function that adds 2.
	var add2 = makeAdder(2);
	// Create a function that adds 4.
	var add4 = makeAdder(4);

  print(add2(3) == 5);
  print(add4(3) == 7);
}
```

## Return values

All functions return a value. If no return value is specified, the statement return null.

```dart
foo() { }
assert(foo() == null);
```
