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

## The main() function
