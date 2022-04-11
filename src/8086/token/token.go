package token

type TokenType string

type Token struct {
	Type    TokenType
	Literal string
}

const (
	ILLEGAL = "ILLEGAL"
	EOF     = "EOF"

  REGISTER = "REGISTER"
  SEGMENT = "SEGMENT"
  POINTER = "POINTER"

	IDENT = "IDENT"
	SRC   = "SRC"

	COMMA = ","
  PERIOD = "."

  LBRAKET = "["
  RBRAKET = "]"

  MOV = "MOV"
  ADD = "ADD"
  DEC = "DEC"
  JNZ = "JNZ"
)

var keywords = map[string]TokenType{
  "ax": REGISTER,
  "bx": REGISTER,
  "cx": REGISTER,
  "dx": REGISTER,
  "al": REGISTER,
  "bl": REGISTER,
  "cl": REGISTER,
  "dl": REGISTER,
  "ah": REGISTER,
  "bh": REGISTER,
  "ch": REGISTER,
  "dh": REGISTER,
  "ss": SEGMENT,
  "cs": SEGMENT,
  "ds": SEGMENT,
  "es": SEGMENT,
  "sp": POINTER,
  "bp": POINTER,
  "ip": POINTER,
  "si": POINTER,
  "di": POINTER,
  "MOV": MOV,
  "ADD": ADD,
  "DEC": DEC,
  "JNZ": JNZ,
}

func LookupIdent(ident string) TokenType {
	if tok, ok := keywords[ident]; ok {
		return tok
	}
	return IDENT
}
