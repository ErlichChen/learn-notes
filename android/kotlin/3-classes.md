# Classes

## Declaration

```kotlin
class Shape {
	var numberOfSides = 0
	fun simpleDescription() = "A shape with $numberOfSides sides."
}
```

## Usage

```kotlin
var shape = Shape()
shape.numberOfSides = 7
var shapeDescription = shape.simpleDescription()
```

## Subclass

```kotlin
open class NameShape(val name: String) {
	var numberOfSides = 0

	open fun simpleDescription() = "A shape with $numberOfSides sides."
}

class Square(var sideLength: BigDecimal, name: String) : NamedShape(name) {
	init {
		numberOfSides = 4
	}

	fun area() = sideLength.pow(2)

	override fun simpleDescription() = "A square with sides of length $sideLength."
}

val test = Square(BigDecimal("5.2"), "square")
test.area()
test.simpleDescription()
```

## Checking Type

```kotlin
var movieCount = 0
var songCount = 0

for (item in library) {
	if (item is Movie) {
		moveCount += 1
	} else if (item is Song) {
		songCount += 1
	}
}
```

## Pattern Matching

```kotlin
val nb = 42
when (nb) {
	in 0..7, 8, 9 -> println("single digit")
	10 -> println("double digits")
	in 11...99 -> println("double digits")
	in 100...999 -> println("triple digits")
	else -> println("four or move digits")
}
```

## Downcasting

```kotlin
for (current in someObjects) {
	if (current is Movie) {
		println("Movie: '$(current.name)', " + "dir. $(current.director)")
	}
}
```

## Protocol

```kotlin
interface Nameable {
	fun name(): String
}

fun f<T: Nameable>(x: T) {
	println("Name is " + x.name())
}
```

## Extensions

```kotlin
val Double.km: Double get() = this * 1000
val Double.m:  Double get() = this
val Double.cm: Double get() = this / 100
val Double.mm: Double get() = this / 1000
val Double.ft: Double get() = this / 3.28084

val oneInch = 25.4.mm
print("One inch is $oneInch meters")
let threeFeet = 3.0.ft
print("Three feet is $threeFeet meters")
```