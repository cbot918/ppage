package main

import (
	"fmt"
	"os"
)

const (
	PRINT      = "print"
	LEFTPAREN  = "("
	RIGHTPAREN = ")"
)

var (
	log = fmt.Println
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

		if string(content[count]) == "\"" {
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
				temp = append(temp, "STRING_LITERAL")
			}
		}
	}

	return temp
}

func GetAst() {}

func Process() {}

func main() {
	program := GetContent(fileName)

	strings := GetStrings(program)
	log("strings: ", strings)

	tokens := GetTokens(strings)
	log("tokens: ", tokens)
	// SkipWhitespace()
}
