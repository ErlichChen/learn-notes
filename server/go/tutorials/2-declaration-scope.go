package main

import "fmt"

func main() {

	// iota
	const (
		c0     = 10         // 0
		c1, c2 = iota, iota // 1
		c3     = iota       // 2
	)
	fmt.Printf("iota c0: %d - c1: %d - c2: %d - c3: %d\n", c0, c1, c2, c3)
}
