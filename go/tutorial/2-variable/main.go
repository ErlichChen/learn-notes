package main

import "fmt"

func main() {

	var a int // declaration
	a = 10    // assignment
	a = a + 25
	fmt.Println(a)

	PI := 3.14159
	r := 2.5
	s := PI * r * r
	fmt.Println("size: ", s)

	a, b := 10, 20
	a, b = b, a

	fmt.Println(a)
	fmt.Println(b)

	_, b, _, d := 1, 2, 3, 4

	//fmt.Println(_)
	fmt.Println(b)
	fmt.Println(d)
	//fmt.Println(_)
}
