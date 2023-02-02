package main

import (
	"fmt"
	"langy2/src/parser"
	"langy2/src/token"
)

func main() {
	program := "(add 10 (subtract 10 6))"
	tokens := token.NewTokenizer(program)
	// fmt.Println(json.MarshalIndent(tokens.Get(), "", "  "))

	// fmt.Println(tokens.Get())
	p := parser.NewParser(tokens.Get())
	p.Run()
	fmt.Println(p.Get())
}
