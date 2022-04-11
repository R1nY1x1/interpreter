#pragma once

#include <string.h>

enum TokenType {
  ILLEGAL,
  EndOfFile,
  REGISTER,
  SEGMENT,
  POINTER,
  IDENT,
  SRC,
  COMMA,
  PERIOD,
  LBRAKET,
  RBRAKET,
  MOV,
  ADD,
  DEC,
  JNZ,
};

struct Token {
  enum TokenType Type;
  const char *Literal;
  const char *TypeStr;
};

typedef struct Token Token;

Token newToken(enum TokenType Type, const char *Literal) {
  struct Token tok;
  tok.Type = Type;
  tok.Literal = Literal;
  switch (tok.Type) {
    case ILLEGAL:
      tok.TypeStr = "ILLEGAL";
      break;
    case EndOfFile:
      tok.TypeStr = "EndOfFile";
      break;
    case REGISTER:
      tok.TypeStr = "REGISTER";
      break;
    case SEGMENT:
      tok.TypeStr = "SEGMENT";
      break;
    case POINTER:
      tok.TypeStr = "POINTER";
      break;
    case IDENT:
      tok.TypeStr = "IDENT";
      break;
    case SRC:
      tok.TypeStr = "SRC";
      break;
    case COMMA:
      tok.TypeStr = "COMMA";
      break;
    case PERIOD:
      tok.TypeStr = "PERIOD";
      break;
    case LBRAKET:
      tok.TypeStr = "LBRAKET";
      break;
    case RBRAKET:
      tok.TypeStr = "RBRAKET";
      break;
    case MOV:
      tok.TypeStr = "MOV";
      break;
    case ADD:
      tok.TypeStr = "ADD";
      break;
    case DEC:
      tok.TypeStr = "DEC";
      break;
    case JNZ:
      tok.TypeStr = "JNZ";
      break;
  } 
  return tok;
}

enum TokenType LookupIdent(char *ident) {
  enum TokenType tok = IDENT;
  if (
    (strcmp(ident, "AX") == 0) ||
    (strcmp(ident, "BX") == 0) ||
    (strcmp(ident, "CX") == 0) ||
    (strcmp(ident, "DX") == 0) ||
    (strcmp(ident, "AL") == 0) ||
    (strcmp(ident, "BL") == 0) ||
    (strcmp(ident, "CL") == 0) ||
    (strcmp(ident, "DL") == 0) ||
    (strcmp(ident, "AH") == 0) ||
    (strcmp(ident, "BH") == 0) ||
    (strcmp(ident, "CH") == 0) ||
    (strcmp(ident, "DH") == 0)) {
    tok = REGISTER;
  } else if (
    (strcmp(ident, "CS") == 0) ||
    (strcmp(ident, "SS") == 0) ||
    (strcmp(ident, "DS") == 0) ||
    (strcmp(ident, "ES") == 0)) {
    tok = SEGMENT;
  } else if (
    (strcmp(ident, "SI") == 0) ||
    (strcmp(ident, "DI") == 0) ||
    (strcmp(ident, "BP") == 0) ||
    (strcmp(ident, "SP") == 0) ||
    (strcmp(ident, "IP") == 0)) {
    tok = POINTER;
  } else if (strcmp(ident, "MOV") == 0) {
    tok = MOV;
  } else if (strcmp(ident, "ADD") == 0) {
    tok = ADD;
  } else if (strcmp(ident, "DEC") == 0) {
    tok = DEC;
  } else if (strcmp(ident, "JNZ") == 0) {
    tok = JNZ;
  }
  return tok;
}
