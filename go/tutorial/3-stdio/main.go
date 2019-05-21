package main

import "fmt"

func main() {
	fmt.Print("Hello ")
	fmt.Println("Developer")
	fmt.Println("learning golang std io: ")

	fmt.Print(1)
	fmt.Println(". input string")
	var str string
	fmt.Scanf("%s", &str)
	fmt.Printf("---> %s\n", str)

	fmt.Print(2)
	fmt.Println(". input int")
	var number int
	fmt.Scanf("%d", &number)
	fmt.Printf("---> %d\n", number)

	fmt.Print(3)
	fmt.Println(". input 2 float64")
	var f1 float64
	var f2 float64
	fmt.Scan(&f1, &f2)
	fmt.Printf("面积：%.3f\n", f1*f2)

}
