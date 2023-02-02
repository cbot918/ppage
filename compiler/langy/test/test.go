package main

import "fmt"

func main() {
	str := "hello world"
	fmt.Println([]rune(str))
	fmt.Println([]byte(str))
	fmt.Println(string(str[0]))
	fmt.Println(len([]byte(str)))

	str2 := "你好我好"
	fmt.Println([]rune(str2))
	fmt.Println([]byte(str2))
	fmt.Println(string([]rune(str2)[0]))
	fmt.Println(len([]rune(str2)))
}
