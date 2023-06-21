package main

import (
	"fmt"
	"os"
)

var log = fmt.Println

var Index int
var Content []byte

const (
	defaultPath = "./print.txt"
)

const (
	PRINT      = "print"
	LEFTPAREN  = "("
	RIGHTPAREN = ")"
	DQUOTE     = "\""
	PLUS       = "+"
	MINUS      = "-"
)

const (
	T_PRINT      = "PRINT"
	T_LEFTPAREN  = "LEFTPAREN"
	T_RIGHTPAREN = "RIGHTPAREN"
	T_DQUOTE     = "DQUOTE"
	T_NUMBER     = "NUMBER"
	T_PLUS       = "PLUS"
	T_MINUS      = "MINUS"
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

func isNumber(char byte) bool {
	return char >= '0' && char <= '9'
}

func GetOneString() string {
	tempS := ""
	for {
		tempS += string(Content[Index])
		Index += 1
		if Index >= len(Content) || !isChar(Content[Index]) {
			break
		}
	}
	return tempS
}

func GetOneNumber() string {
	tempN := ""
	for {
		log("for")
		tempN += string(Content[Index])
		Index += 1
		log("index in GetOneNumber: ", Index)
		log("length of content: ", len(Content))

		if Index >= len(Content) || !isNumber(Content[Index]) {
			break
		}
	}
	return tempN
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

	var strs []string
	for Index < codeLen {
		log("strs: ", strs)
		// log(Index, string(Content[Index]))
		// string a string
		if isChar(Content[Index]) {
			strs = append(strs, GetOneString())
			continue
		}

		if isNumber(Content[Index]) {
			strs = append(strs, GetOneNumber())
			continue
		}
		switch string(Content[Index]) {
		case LEFTPAREN:
			strs = append(strs, string(Content[Index]))
		case RIGHTPAREN:
			strs = append(strs, string(Content[Index]))
		case PLUS:
			log("+")
			strs = append(strs, string(Content[Index]))
		case MINUS:
			strs = append(strs, string(Content[Index]))
		case DQUOTE:
			strs = append(strs, GetStringUntil("\""))
		}

		if Index < codeLen-1 {
			Index++
			continue
		} else {

			break
		}
	}

	return strs
}

func GetTokens(strings []string) []string {
	tokens := []string{}
	numberOrLiteral := "NUMBER"
	for _, item := range strings {

		if isChar(byte(item[0])) {
			numberOrLiteral = "LITERAL"
		}

		switch item {
		case LEFTPAREN:
			tokens = append(tokens, T_LEFTPAREN)
		case RIGHTPAREN:
			tokens = append(tokens, T_RIGHTPAREN)
		case PRINT:
			tokens = append(tokens, T_PRINT)
		case PLUS:
			tokens = append(tokens, T_PLUS)
		default:
			tokens = append(tokens, numberOrLiteral)
		}
	}
	return tokens
}

func GetFilePath() string {
	args := os.Args
	if len(args) == 2 {
		log("input: ", args[1])
		return "./" + args[1]
	}
	return defaultPath
}

func main() {
	// init global var
	Index = 0
	Content = GetContent(GetFilePath())

	// content to strings
	strings := GetStrings()
	log("strings: ", strings)

	tokens := GetTokens(strings)
	log("tokens: ", tokens)
	// Procestrs(tokens)
}
