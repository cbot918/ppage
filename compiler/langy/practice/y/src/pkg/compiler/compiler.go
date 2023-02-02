package compiler

import (
	"y/src/pkg/parser"
)

type compiler struct{}

func NewCompiler(ast parser.Node) *compiler {
	c := new(compiler)
	return c
}
