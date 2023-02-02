package parser

import (
	"fmt"
	"langy2/src/token"
	"log"
)

type Parser struct {
	tokens []token.Token
	Ast    node
	pc     int
}

type node struct {
	kind   string
	name   string
	value  string
	body   []node
	params []node
}

func NewParser(tokens []token.Token) *Parser {
	p := new(Parser)
	p.tokens = tokens
	fmt.Println(len(p.tokens))
	return p
}

func (p *Parser) Get() node {
	return p.Ast
}

func (p *Parser) Run() {
	temp := node{
		kind: "Program",
		body: []node{},
	}

	for p.pc < len(p.tokens) {
		// token := p.tokens[p.pc]

		temp.body = append(temp.body, p.walk())
		// // fmt.Println(p.pc)
		// if token.Kind == "leftparen" {
		// 	fmt.Println("leftparen")
		// 	p.pc += 1
		// 	continue
		// }

		// if token.Kind == "letter" {
		// 	fmt.Println("letter")
		// 	p.pc += 1
		// 	n := node{
		// 		kind:   "CallExpression",
		// 		name:   token.Value,
		// 		params: []node{},
		// 	}

		// }

	}
	p.Ast = temp
}

func (p *Parser) walk() node {

	fmt.Println(p.Get())

	if p.tokens[p.pc].Kind == "number" {
		fmt.Println("number")
		val := p.tokens[p.pc].Value
		p.pc++
		return node{
			kind:  "NumberLiteral",
			value: val,
		}
	}

	if p.tokens[p.pc].Kind == "leftparen" {
		fmt.Println("leftparen")
		p.pc++

		n := node{
			kind:   "CallExpression",
			name:   p.tokens[p.pc].Value,
			params: []node{},
		}
		p.pc++

		for p.tokens[p.pc].Kind != "rightparen" {
			n.params = append(n.params, p.walk())
		}
		p.pc++
		return n

	}

	log.Fatal(p.tokens[p.pc].Kind)
	return node{}
}
