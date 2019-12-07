# Functions

## Functions

```kotlin
fun greet(name: String, day: String): String {
	return "Hello $name, today is $day."
}
greet("Bob", "Tuesday")
```

## Tuple Return

```kotlin
data class GetGasPrices(val a: Double, val b: Double, val c: Double)
fun getGasPrices = GasPrices(3.59, 3.69, 3.79)
```

## Variable Number Of Arguments

```kotlin
fun sumOf(varag numbers: Int): Int {
	var sum = 0
	for (number in numbers) {
		sum += number
	}
	return sum
}
sumOf(1, 2, 3)

fun sumOf(vararg numbers: Int) = numbers.sum()
```

## Function Type

```kotlin
fun makeAdd(): (Int) -> Int {
	val addOne = fun(number: Int): Int {
		return 1 + number
	}
	return addOne
}
val add = makeAdd()
add(1)

fun makeAdd() = fun(number: Int) = 1 + number
```

## Map

```kotlin
val numbers = listOf(1, 2, 3, 4)
numbers.map { 3 * it }
```

## Sort

```kotlin
listOf(1, 2, 3).sorted()
```

## Named Arguments

```kotlin
fun area(width: Int, height: Int) = width * height
area(width = 2, height = 3)

area(2, height = 2)
area(height = 3, width = 2)
```