package main

import (
	"fmt"
	"os"
)

const (
	PRINT      = "PRINT"
	LEFTPAREN  = "LEFTPAREN"
	RIGHTPAREN = "RIGHTPAREN"
	LITERAL    = "LITERAL"
)

var (
	log      = fmt.Println
	LITERALS = []string{}
)

var (
	fileName = "./tests/print.yo"
)

func logs(data byte) {
	fmt.Println(string(data))
}

func GetContent(fileName string) string {
	data, err := os.ReadFile(fileName)
	if err != nil {
		panic(err)
	}

	return string(data)
}

func isString(data byte) bool {
	return data >= 'a' && data <= 'z'
}

func GetStrings(content string) []string {

	count := 0
	temp := ""

	target := []string{}

	for count < len(content) {

		if isString(content[count]) {
			temp = ""
			for isString(content[count]) {
				temp += string(content[count])
				count += 1
			}
			target = append(target, temp)
		}

		if string(content[count]) == "(" {
			target = append(target, "(")
			count += 1
		}

		if string(content[count]) == ")" {
			target = append(target, ")")
			count += 1
		}

		// some issue
		if string(content[count]) == "\"" {
			log("hi")
			count += 1
			temp = ""
			for isString(content[count]) {
				temp += string(content[count])
				count += 1
			}
			target = append(target, temp)
		}

		count += 1
	}

	return target
}

func GetTokens(strings []string) []string {
	var temp []string
	for _, item := range strings {
		switch item {
		case "print":
			{
				temp = append(temp, PRINT)
			}
		case "(":
			{
				temp = append(temp, LEFTPAREN)
			}
		case ")":
			{
				temp = append(temp, RIGHTPAREN)
			}
		default:
			{
				temp = append(temp, LITERAL)
				LITERALS = append(LITERALS, item)
			}
		}
	}

	return temp
}

// func GetAst() {}

func Process(tokens []string) {
	for _, item := range tokens {
		if item == PRINT {
			execPrint(tokens[1:])
		}
	}
}

// workaround
func execPrint(tokens []string) {
	toks := tokens
	toks = toks[1:]
	// fmt.Println("node: ", toks[0])
	fmt.Println(LITERALS[0])
}

func main() {
	log("")
	program := GetContent(fileName)

	strings := GetStrings(program)
	log("strings: ", strings)

	tokens := GetTokens(strings)
	log("tokens: ", tokens)

	log("")
	Process(tokens)
}
