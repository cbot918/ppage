package main

import (
	"fmt"
	"os"
)

var log = fmt.Println

var Index int
var Content []byte

const (
	path = "./code.txt"
)

const (
	PRINT      = "print"
	LEFTPAREN  = "("
	RIGHTPAREN = ")"
)

func GetContent(path string) []byte {
	code, err := os.ReadFile(path)
	if err != nil {
		panic(err)
	}
	return code
}

func isChar(char byte) bool {
	return char >= 'a' && char <= 'z' || char >= 'A' && char <= 'Z'
}

func GetOneString() string {
	tempS := ""
	for {
		tempS += string(Content[Index])
		Index += 1
		if !isChar(Content[Index]) {
			break
		}
	}
	return tempS
}

func GetStringUntil(target string) string {
	tempS := ""
	Index += 1 // skip left "
	for {
		tempS += string(Content[Index])
		Index += 1
		if string(Content[Index]) == target {
			break
		}
	}
	return tempS
}

func GetStrings() []string {

	codeLen := len(Content)

	var tempA []string
	for {

		// string a string
		if isChar(Content[Index]) {
			tempA = append(tempA, GetOneString())
			continue
		}

		// string a (
		if string(Content[Index]) == "(" {
			tempA = append(tempA, string(Content[Index]))
		}

		// string a )
		if string(Content[Index]) == ")" {
			tempA = append(tempA, string(Content[Index]))
		}

		// deal with ""
		if string(Content[Index]) == "\"" {
			tempA = append(tempA, GetStringUntil("\""))
		}

		if Index < codeLen-1 {
			Index++
			continue
		} else {
			break
		}

	}

	return tempA
}

func main() {
	// init global var
	Index = 0
	Content = GetContent(path)

	// content to strings
	strings := GetStrings()
	log(strings)

	// tokens := GetTokens(strings)

	// Process(tokens)
}
