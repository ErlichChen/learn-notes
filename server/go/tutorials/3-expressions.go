package main

import "fmt"

func main() {

	// operation
	a, b := 10, 3

	fmt.Printf("a + b = %d\n", a+b)  // addition
	fmt.Printf("a - b = %d\n", a-b)  // subtraction
	fmt.Printf("a * b = %d\n", a*b)  // multiplication
	fmt.Printf("a / b = %d\n", a/b)  // division
	fmt.Printf("a %% b = %d\n", a%b) // remainder
	a++                              // increment
	b--                              // decrement
	fmt.Printf("a++ = %d\n", a)
	fmt.Printf("b+-- = %d\n", b)

	// comparison operator
	fmt.Printf("a == b = %t\n", a == b)
	fmt.Printf("a != b = %t\n", a != b)
	fmt.Printf("a >= b = %t\n", a >= b)
	fmt.Printf("a <= b = %t\n", a <= b)

	// logical operator
	c, d := 9, 4
	fmt.Printf("!(b == c) = %t\n", !(b == c))
	fmt.Printf("a > b && c < d = %t\n", a > b && c < d)
	fmt.Printf("a < b || c > d = %t\n", a < b || c > d)

}
