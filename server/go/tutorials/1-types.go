/*
 * Types
 */
package main

import "unsafe"
import "fmt"

func main() {

	// boolean types
	var b bool = true
	fmt.Printf("%T %t size: %d\n", b, b, unsafe.Sizeof(b))

	// numeric types
	var ui uint = 1
	var ui8 uint8 = 255
	var ui16 uint16 = 65535
	var ui32 uint32 = 4294967295
	var ui64 uint64 = 18446744073709551615

	fmt.Printf("%T %d size: %d\n", ui, ui, unsafe.Sizeof(ui))
	fmt.Printf("%T %d size: %d\n", ui8, ui8, unsafe.Sizeof(ui8))
	fmt.Printf("%T %d size: %d\n", ui16, ui16, unsafe.Sizeof(ui16))
	fmt.Printf("%T %d size: %d\n", ui32, ui32, unsafe.Sizeof(ui32))
	fmt.Printf("%T %d size: %d\n", ui64, ui64, unsafe.Sizeof(ui64))

	var i int = 1
	var i8 int8 = 127
	var i16 int16 = 32767
	var i32 int32 = 2147483647
	var i64 int64 = 9223372036854775807

	fmt.Printf("%T %d size: %d\n", i, i, unsafe.Sizeof(i))
	fmt.Printf("%T %d size: %d\n", i8, i8, unsafe.Sizeof(i8))
	fmt.Printf("%T %d size: %d\n", i16, i16, unsafe.Sizeof(i16))
	fmt.Printf("%T %d size: %d\n", i32, i32, unsafe.Sizeof(i32))
	fmt.Printf("%T %d size: %d\n", i64, i64, unsafe.Sizeof(i64))

	var f32 float32 = 3.14
	var f64 float64 = 3.14
	fmt.Printf("%T %.2f size: %d\n", f32, unsafe.Sizeof(f32))
	fmt.Printf("%T %.2f size: %d\n", f64, unsafe.Sizeof(f64))

	var c64 complex64 = complex(1, -1)
	var c128 complex128 = complex(1, -1)
	fmt.Printf("%T %g size: %d\n", c64, c64, unsafe.Sizeof(c64))
	fmt.Printf("%T %g size: %d\n", c128, c128, unsafe.Sizeof(c128))

	// string types
	var c int = 97
	fmt.Printf("%T %d char %c\n", c, c)

	var str string = "hello go"
	fmt.Printf("%T %s size: %d\n", str, str, unsafe.Sizeof(str))

	// array types
	var arr = [3]int{1, 2, 3}
	fmt.Printf("%T size: %d\n", arr, unsafe.Sizeof(arr))

	// slice types
	var slice = []int{1, 2, 3}
	fmt.Printf("%T size: %d\n", slice, unsafe.Sizeof(slice))

	// struct types
	type User struct {
		name string
		age  int
	}
	var user1 User
	fmt.Printf("%T size: %d\n", user1, unsafe.Sizeof(user1))

	// pointer types
	var ip1 int = 1
	var ip2 *int
	ip2 = &ip1
	fmt.Println("ip1 addr: %p", &ip1)
	fmt.Println("ip2 addr: %p", ip2)

	// function types
	fmt.Printf("%T size: %d\n", add, unsafe.Sizeof(add))

	// interface types
	type inter interface {
		func1()
	}
	var inter1 inter
	fmt.Printf("%T size: %d\n", inter1, unsafe.Sizeof(inter1))

	// map types
	var users map[string]string = make(map[string]string)
	users["a"] = "admin"
	fmt.Printf("%T size: %d\n", users, unsafe.Sizeof(users))

	// channel types
	var ch1 = make(chan int, 3)
	ch1 <- 2
	ch1 <- 1
	ch1 <- 3
	elem1 := <-ch1
	fmt.Printf("%T the first element received from channel ch1: %v\n", ch1, elem1)

	// PI := 3.14159
	// r := 2.5
	// s := PI * r * r
	// fmt.Println("size: ", s)

	// a, b := 10, 20
	// a, b = b, a

	// _, b, _, d := 1, 2, 3, 4

	// fmt.Println(_)
	// fmt.Println(b)
	// fmt.Println(d)
	// fmt.Println(_)

	//计算机能够识别的进制  二进制 八进制 十进制 十六进制

	// a := 123   //十进制数据
	// b := 0123  //八进制数据 以0开头的数据是八进制
	// c := 0xabc //十六进制  以0x开头的数据是十六进制
	//go语言中不能直接表示二进制数据

	//fmt.Println(a)
	//fmt.Println(b)
	//fmt.Println(c)
	//%b 占位符 表示输出一个二进制数据
	//fmt.Printf("二进制值为：%b\n",a)
	//fmt.Printf("二进制值为：%b\n",b)
	//fmt.Printf("二进制值为：%b\n",c)
	//%o 占位符 表示输出一个八进制数据
	//fmt.Printf("%o\n",a)
	//fmt.Printf("%o\n",b)
	//fmt.Printf("%o\n",c)
	//%x %X 占位符 表示输出一个十六进制数据
	// fmt.Printf("%X\n", a)
	// fmt.Printf("%X\n", b)
	// fmt.Printf("%X\n", c)
	// s := ' '
	// fmt.Printf("%T", s)
}

func add(a int, b int) int {
	return a + b
}

// func main2() {
// 	mainStr()
// }

// func mainStr() {
// 	var a byte = 'a'
// 	var b string = "a"
// 	// 换行\n \\表示一个、
// 	var c string = "hello\nstring"
// 	fmt.Println(a)
// 	fmt.Println(b)
// 	fmt.Println(c)
// 	// 在go语言中一个汉字算成3个字符，为了和linux同一处理
// 	num := len(c)
// 	fmt.Println(num)
// }
