package parser

import (
	"y/src/pkg/tokenizer"
)

type parser struct {
	Ast Node
}

type Node struct{}

func NewParser(tokens []tokenizer.Token) *parser {
	p := new(parser)
	return p
}

func (p *parser) Get() Node {
	return p.Ast
}
