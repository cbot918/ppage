package tokenizer

type tokenizer struct {
	program string
	tokens  []Token
}

type Token struct {
	kind  string
	value string
}

func NewTokenizer(program string) *tokenizer {
	t := new(tokenizer)
	t.program = program
	return t
}

func (t *tokenizer) Get() []Token {
	return t.tokens
}
