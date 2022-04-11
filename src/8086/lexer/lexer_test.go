package lexer

import (
	"testing"

	"8086/token"
)

func TestNextToken(t *testing.T) {
	input := `
    MOV ax, 0
    MOV cx, a
    ADD ax, cx
    DEC cx
    JNZ 
  `

	tests := []struct {
		expectedType    token.TokenType
		expectedLiteral string
	}{
    {token.MOV, "MOV"},
    {token.REGISTER, "ax"},
    {token.COMMA, ","},
    {token.SRC, "0"},
    {token.MOV, "MOV"},
    {token.REGISTER, "cx"},
    {token.COMMA, ","},
    {token.IDENT, "a"},
    {token.ADD, "ADD"},
    {token.REGISTER, "ax"},
    {token.COMMA, ","},
    {token.REGISTER, "cx"},
    {token.DEC, "DEC"},
    {token.REGISTER, "cx"},
    {token.JNZ, "JNZ"},
    {token.EOF, ""},
	}

	l := New(input)

	for i, tt := range tests {
		tok := l.NextToken()

		if tok.Type != tt.expectedType {
			t.Fatalf("tests[%d] - tokentype wrong. expected=%q, got=%q",
				i, tt.expectedType, tok.Type)
		}

		if tok.Literal != tt.expectedLiteral {
			t.Fatalf("tests[%d] - literal wrong. expected=%q, got=%q",
				i, tt.expectedLiteral, tok.Literal)
		}
	}
}
