# Variables and Built-in Types

## Variables

```dart
// create a variable and initalize it.
// variables store references. The variable called name contains reference to a String object with a value of "test".
var name = 'test';

// The type of the name variable is inferred to be String, if an object isn’t restricted to a single type, specify the Object or dynamic type.
dynamic name = 'test';

// explicitly declare
String name = 'test';
```

### Default value

Unintialized variables have an initial value of null, everything else in Dart are objects.

```dart
int line;
assert(line == null);
```

### Final and const

```dart
// a final variable can be set only once.
final name = 'test'; // Error: name = 'test1';
final String nickname = 'test';

// a const variable is a compile-time constant.
final foo = const []; // Error: foo = [1];
```

## Built-in Types

### numbers

Integer(int) values no larger than 64 bits, depending on the platform.
64-bit (double-precision) floating-point numbers, as specified by the IEEE 754 standard.

```dart
var x = 1;
var hex = 0xff;
```

### strings

### booleans

### lists

### sets

### maps

### runes

### symbols
