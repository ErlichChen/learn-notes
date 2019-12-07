# Variables Constants

```kotlin
var myVariable = 42
myVariable = 50
val myConstant = 42
```

## Explicit Types

```kotlin
val explicitDouble: Double = 70.0;
```

## Type Coercion

```kotlin
val label = "The width is"
val width = 94
val widthLabel = label + width
```

## String Interpolation

```kotlin
val apples = 3
val oranges = 5
val fruitSummary = "I have $(apples + oranges) " + "pieces of fuit."
```

## Range Operator

```kotlin
val names = arrayOf("str1", "str2", "str3")
val count = names.count()
for (i in 0..count - 1) {
	println("Persion ${i + 1} is called ${name[i]}")
}
```

## Inclusive Range Operator

```kotlin
for (index in 1..5) {
	println("$index times 5 is ${index * 5}")
}
```

## Arrays

```kotlin
val arr = arrayOf("str1", "str2", "str3")
arr[1] = "str4"
```

## Maps

```kotlin
val maps = mutableMapOf(
	"key1" to "value1",
	"key2" to "value2",
)
maps["key3"] = "value3"
```


## Empty Collections

```kotlin
let emptyArray = arrayOf<String>()
let emptyMap = mapOf<String, Float>()
```

