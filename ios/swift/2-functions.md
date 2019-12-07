# Functions

## Functions

```swift
func greet(_name: String, _day: String) -> String {
	return "Hello \(name), today is \(day)."
}
greet("Bob", "Tuesday")
```

## Tuple Return

```swift
func getGasPrices() -> (Double, Double, Double) {
	return (3.59, 3.69, 3.79)
}
```

## Variable Number Of Arguments

```swift
func sumOf(_numbers: Int...) -> Int {
	var sum = 0
	for number in numbers {
		sum += number
	}
	return sum
}
sumOf(1, 2, 3)
```

## Function Type

```swift
func makeAdd() -> (Int -> Int) {
	func addOne(number: Int) -> Int {
		return 1 + number
	}
	return addOne
}
let add = makeAdd()
add(1)
```

## Map

```swift
let numbers = [1, 2, 3]
numbers.map { 3 * $0 }
```

## Sort

```swift
var arr = [1, 2, 3]
arr.sort()
```

## Named Arguments

```swift
func area(width: Int, height: Int) -> Int {
	return width * height
}
area(width: 2, height: 3)
```
