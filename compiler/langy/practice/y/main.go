package main

import (
	"fmt"
	"os"

	c "y/src/pkg/compiler"
	p "y/src/pkg/parser"
	t "y/src/pkg/tokenizer"

	u "y/util"
)

func main() {
	content, err := os.ReadFile("main.ya")
	u.Checke(err, "readfile error")

	tokens := t.NewTokenizer(string(content)).Get()
	ast := p.NewParser(tokens).Get()
	c.NewCompiler(ast)

	fmt.Println(string(content))
	for _, char := range content {
		fmt.Printf("%q", string(char))
	}
	fmt.Println(string(content[0]))
}
