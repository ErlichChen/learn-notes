package main

import "fmt"

func main() {

	// bool
	var bo1 bool
	fmt.Println(bo1)
	bo1 = true
	fmt.Println(bo1)
	bo2 := true
	fmt.Println(bo2)

	// float
	var fl32 float32
	var fl64 float64
	// float32 7 valid numbers, add 1 to end of number
	fl32 = 3.141593400000000
	// float64 15 valid numbers
	fl64 = 3.1415936273242342324367464375
	fmt.Println(fl32)
	fmt.Println(fl64)

	// byte
	var b1 byte = '0'
	var b2 byte = 'a'
	fmt.Println(b1)
	fmt.Println(b2)
	fmt.Printf("%c,%c", b1, b2)

	// string
	var str string = "hello literals"
	fmt.Println(str)
}
