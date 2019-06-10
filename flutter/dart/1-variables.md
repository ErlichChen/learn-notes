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

var y = 1.1;
var exponents = 1.42e5;

// String --> int
var one = int.parse('1');
assert(one == 1);

// String --> double
var onePointOne = double.parse('1.1');
assert(onePointOne == 1.1);

// int --> String
String oneAsString = 1.toString();
assert(oneAsString == '1');

// double --> String
String piAsString = 3.14159.toStringAsFixed(2);
assert(piAsString == '3.14');
```

### strings

A Dart string is a sequence of UTF-16 code units.

```dart
var s1 = 'Single quotes';
var s2 = "double quotes";
var s3 = 'string interpolation';
assert('${s3}');

var s4 = '''
multi-line string
''';

var s5 = r'a raw string, not even \n gets special treatment.';
```

### booleans

```dart
// Check for an empty string.
var fullName = '';
assert(fullName.isEmpty);

// Check for zero.
var hitPoints = 0;
assert(hitPoints <= 0);

// Check for null.
var unicorn;
assert(unicorn == null);

// Check for NaN.
var iMeantToDoThis = 0 / 0;
assert(iMeantToDoThis.isNaN);
```

### lists

Arrays are list objects, can't add different objects to this list, the analyzer or runtime raises an error.

```dart
var list = [1, 2, 3];
list[1] = 1;
assert(list[1] == 1);

var consList = const [1, 2, 3];
// consList[1] = 1; // Uncommenting this causes an error.

// spread list
var list2 = [0, ...list];
assert(list2.length == 4);

// spread operator might be null
var list0;
var list3 = [0, ...?list0];
assert(list3.length == 1);

// conditional
var list4 = [1, 2, 3, if(true) 4];

// repetition
var index = [1, 2, 3];
var list5 = ['#0', for (var i in index) '#$i'];
assert(list5[1] == '#1');
```

### sets

A set in Dart is an unordered collection of unique items.

```dart
var set1 = {'item1', 'item2'};

// create an empty set
var set2 = <String>{};
Set<String> set3 = {};

// Add items to an existing set
var set3 = <String>();
set3.add('item3');
set3.addAll(set1);

// the number of items
assert(set3.length == 3);

final consSet = const {'item1'};
consSet.add('item2'); // Uncommenting this causes an error
```

### maps

```dart
var map = {
	'key1': 'value1',
	'key2': 'value2'
}

// create new map
var map1 = Map();
map1['key3'] = 'value3';
assert(map1['key1'] == 'value1')
assert(map1.length == 3);

final map2 = const {
	'key1': 'value1',
	'key2': 'value2'
}
```

### runes

The runes are the UTF-32 code points of a string

```dart
var clapping = '\u{1f44f}';
print(clapping);
print(clapping.codeUnits);
print(clapping.runes.toList());

Runes input = new Runes('\u{1f44d}');
print(new String.fromCharCodes(input));
```

### symbols

A symbol object represents an operator or identifier declared in a Dart program. You might never need to use symbols.

```dart
// Symbol literals are compile-time constants
#testAPI
```
