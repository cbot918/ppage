package main

import (
	"fmt"
	"log"

	u "langy/util"
)

/*
tokenizer
compiler
ast
*/

// tokenizer
type token struct {
	kind  string
	value string
}

func tokenizer(input string) []token {

	input += "\n"

	current := 0

	var tokens = []token{}

	for current < len([]rune(input)) {
		fmt.Printf("%q:%d\n", []rune(input)[current], current)
		char := string([]rune(input)[current])

		if char == "(" {
			tokens = append(tokens, token{
				kind:  "paren",
				value: "(",
			})
			current += 1
			continue
		}

		if char == ")" {
			tokens = append(tokens, token{
				kind:  "paren",
				value: ")",
			})
			current++
			continue
		}

		if char == " " {
			current++
			continue
		}

		if isNumber(char) {
			value := ""
			for isNumber(char) {
				value += char
				current++
				char = string([]rune(input)[current])
			}

			tokens = append(tokens, token{
				kind:  "number",
				value: value,
			})
			continue
		}

		if isLetter(char) {
			value := ""
			for isLetter(char) {
				value += char
				current++
				char = string([]rune(input)[current])
			}

			tokens = append(tokens, token{
				kind:  "name",
				value: value,
			})
			continue
		}
		break
	}

	return tokens
}

func isNumber(char string) bool {
	if char == "" {
		return false
	}
	n := []rune(char)[0]
	if n >= '0' && n <= '9' {
		return true
	}
	return false
}

func isLetter(char string) bool {
	if char == "" {
		return false
	}
	n := []rune(char)[0]
	if n >= 'a' && n <= 'z' {
		return true
	}
	return false
}

// parser

type node struct {
	kind       string
	value      string
	name       string
	callee     *node
	expression *node
	body       []node
	params     []node
	arguments  *[]node
	context    *[]node
}

type ast node

var pc int

var pt []token

func parser(tokens []token) ast {
	pc = 0
	pt = tokens

	ast := ast{
		kind: "Program",
		body: []node{},
	}

	for pc < len(pt) {
		ast.body = append(ast.body, walk())
	}

	return ast
}

func walk() node {
	token := pt[pc]

	if token.kind == "number" {
		pc++
		return node{
			kind:  "NumberLiteral",
			value: token.value,
		}
	}

	if token.kind == "paren" && token.value == "(" {
		pc++
		token = pt[pc]

		n := node{
			kind:   "CallExpression",
			name:   token.value,
			params: []node{},
		}

		pc++
		token = pt[pc]

		for token.kind != "paren" || (token.kind == "paren" && token.value != ")") {
			n.params = append(n.params, walk())
			token = pt[pc]
		}
		pc++
		return n
	}
	log.Fatal(token.kind)
	return node{}
}

func compiler(input string) int {
	tokens := tokenizer(input)
	u.Logg(tokens)
	// ast := parser()
	// nast := transformer()
	// out := codeGenerator()
	return 5
}

func main() {
	program := "(add 10 (subtract 10 6))"
	out := compiler(program)
	fmt.Println(out)
}
