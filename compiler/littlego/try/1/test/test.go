package main

// fmt package provides the function to print anything
import (
	"fmt"
)

func main() {

	// declaring the variable of string type using the var keyword
	var introduction string

	// initializing the introduction string
	introduction = "+"
	fmt.Println("ASCII of ", introduction, "is")

	// printing the ASCII value of each character using %d specifier
	for i := 0; i < len(introduction); i++ {
		fmt.Printf("The ASCII value of %c is %d \n", introduction[i], introduction[i])
	}
	fmt.Println("(Printing the ASCII value using specifier)")
}