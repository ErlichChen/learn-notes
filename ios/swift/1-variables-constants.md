# Variables Constants

```swift
var myVariable = 42
myVariable = 50
let myConstant = 42
```

## Explicit Types

```swift
let explicitDouble: Double = 70;
```

## Type Coercion

```swift
let label = "The width is "
let width = 94
let widthLabel = label + String(width)
```

## String Interpolation

```swift
let apples = 3
let oranges = 5
let fruitSummary = "I have \(apples + orange) " + "pieces of fruit."
```

## Range Operator

```swift
let names = ["str1", "str2", "str3"]
let count = names.count
for i in 0..<count {
	print("Person \(i + 1) is called \(names[i])")
}
```

## Inclusive Range Operator

```swift
for index in 1...5 {
	print("\(index) times 5 is \(index * 5)")
}
```

## Arrays

```swift
var arr = ["str1", "str2", "str3"]
arr[1] = "str4"
```

## Maps

```swift
var maps = [
	"key1": "value1",
	"key2": "value2",
]
maps["key3"] = "value3"
```

## Empty Collections

```swift
let emptyArray = [String]()
let emptyDictionary = [String: Float]()
```