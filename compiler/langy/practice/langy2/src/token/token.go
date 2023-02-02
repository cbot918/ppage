package token

// u "langy/util"

type Tokenizer struct {
	Tokens  []Token
	current int
}

type Token struct {
	Kind  string
	Value string
}

func NewTokenizer(input string) *Tokenizer {
	t := new(Tokenizer)
	t.current = 0
	t.Tokens = []Token{}

	var char string
	for t.current < len([]rune(input)) {
		char = string([]rune(input)[t.current])
		if char == " " {
			t.current += 1
			continue
		}
		t.Tokens = append(t.Tokens, t.tokMatcher(char, input))
	}

	return t
}

func (t *Tokenizer) Get() []Token {
	return t.Tokens
}

func (t *Tokenizer) tokMatcher(char string, input string) Token {
	var tok Token

	if t.isLetter(char) {
		tok.Kind = "letter"
		tok.Value = t.getLetter(input)
	}
	if t.isNumber(char) {
		tok.Kind = "number"
		tok.Value = t.getNumber(input)
	}

	if char == "(" {
		tok.Kind = "leftparen"
		tok.Value = "("
		t.current += 1
	} else if char == ")" {
		tok.Kind = "rightparen"
		tok.Value = ")"
		t.current += 1
	}

	return tok
}

func (t *Tokenizer) isLetter(char string) bool {
	result := false
	c := []rune(char)[0]
	if c >= 'a' && c <= 'z' {
		result = true
	}
	return result
}

func (t *Tokenizer) getLetter(input string) string {
	letter := ""
	for t.isLetter(string([]rune(input)[t.current])) {
		letter += string([]rune(input)[t.current])
		t.current += 1
	}
	return letter
}

func (t *Tokenizer) isNumber(char string) bool {
	c := []rune(char)[0]
	if c >= '0' && c <= '9' {
		return true
	}
	return false
}
func (t *Tokenizer) getNumber(input string) string {
	number := ""
	for t.isNumber(string([]rune(input)[t.current])) {
		number += string([]rune(input)[t.current])
		t.current += 1
	}
	return number
}
