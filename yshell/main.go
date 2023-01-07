// 1. readinput
// 2. save to memory -> read from memory
// 3. save to file -> read from file

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {

	fmt.Println("yshell template")
	fmt.Println("-----------------")
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Print("db > ")
		text, _ := reader.ReadString('\n')
		// convert CRLF to LF
		text = strings.Replace(text, "\r\n", "", -1)

		switch text {
		case "select":
			fmt.Println("select")

		case ".exit":
			os.Exit(1)
		}

		// if strings.Compare("hi", text) == 0 {
		// 	fmt.Println("hello, yale")
		// }
	}

}
