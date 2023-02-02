package main

import (
	"fmt"
	// u "langy/util"
)

const (
	program = "(add 10 (subtract 10 6))"
)

type token struct {
	kind  string
	value string
}

var current int

func tokenizer(input string) []token {
	var char string
	current = 0
	tokens := []token{}
	for current < len([]rune(input)) {
		char = string([]rune(input)[current])
		if char == " " {
			current += 1
			continue
		}
		tokens = append(tokens, tokMatcher(char, input))
	}
	return tokens
}

func tokMatcher(char string, input string) token {
	var t token

	if isLetter(char) {
		t.kind = "letter"
		t.value = getLetter(input)
	}
	if isNumber(char) {
		t.kind = "number"
		t.value = getNumber(input)
	}

	if char == "(" {
		t.kind = "paren"
		t.value = "("
		current += 1
	} else if char == ")" {
		t.kind = "paren"
		t.value = ")"
		current += 1
	}

	return t
}
func isLetter(char string) bool {
	result := false
	c := []rune(char)[0]
	if c >= 'a' && c <= 'z' {
		result = true
	}
	return result
}
func getLetter(input string) string {
	letter := ""
	for isLetter(string([]rune(input)[current])) {
		letter += string([]rune(input)[current])
		current += 1
	}
	return letter
}

func isNumber(char string) bool {
	c := []rune(char)[0]
	if c >= '0' && c <= '9' {
		return true
	}
	return false
}
func getNumber(input string) string {
	number := ""
	for isNumber(string([]rune(input)[current])) {
		number += string([]rune(input)[current])
		current += 1
	}
	return number
}

func main() {
	t := tokenizer(program)
	fmt.Println(t)
}
