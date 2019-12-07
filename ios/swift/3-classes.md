# Classes

## Declaration

```swift
class Shape {
	var numberOfSides = 0
	func simpleDescription() -> String {
		return "A shape with \(numberOfSides) sides."
	}
}
```

## Usage

```swift
var shape = Shape()
shape.numberOfSides = 7
var shapeDescription = shape.simpleDescription()
```

## Subclass

```swift
class NameShape {
	var numberOfSides: Int = 0
	let name: String

	init(name: String) {
		self.name = name
	}

	func simpleDescription() -> String {
		return "A shape with \(numberOfSides) sides."
	}
}

class Square: NamedShape {
	var sideLength: Double

	init(sideLength: Double, name: String) {
		self.sideLength = sideLength
		super.init(name: name)
		self.numberOfSides = 4
	}

	func area() -> Double {
		return sideLength * sideLength
	}

	override func simpleDescription() -> String {
		return "A square with sides of length " + sideLength + "."
	}

	let test = Square(sideLength: 5.2, name: "square")
	test.area()
	test.simpleDescription()
}
```

## Checking Type

```swift
var movieCount = 0
var songCount = 0

for item in library {
	if item is Movie {
		moveCount += 1
	} else if item is Song {
		songCount += 1
	}
}
```

## Pattern Matching

```swift
let nb = 42
switch nb {
	case 0...7, 8, 9: print("single digit")
	case 10: print("double digits")
	case 11...99: print("double digits")
	case 100...999: print("triple digits")
	default: print("four or move digits")
}
```

## Downcasting

```swift
for current in someObjects {
	if let movie = current as? Movie {
		print("Movie: '\(movie.name)', " + "dir. \(movie.director)")
	}
}
```

## Protocol

```swift
protocol Nameable {
	func name() -> String
}

func f<T: Nameable>(x: T) {
	print("Name is " + x.name())
}
```

## Extensions

```swift
extension Double {
	var km: Double { return self * 1_000.0 }
	var m:  Double { return self }
	var cm: Double { return self / 100.0 }
	var mm: Double { return self / 1_000.0 }
	var ft: Double { return self * 3.28084 }
}
let oneInch = 25.4.mm
print("One inch is \(oneInch) meters")
let threeFeet = 3.ft
print("Three feet is \(threeFeet) meters")
```