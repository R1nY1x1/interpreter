#pragma once

#include <stdio.h>
#include "token.h"
#include "lexer.h"

void REPL(void){
  char cmd[32];
  char prompt[4] = ">> ";

  while (1) {
    printf("%s", prompt);
    scanf("%[^\n]%*c", cmd);

    Lexer l = newLexer(cmd);
    Token tok;
    tok = l.NextToken(&l);
    while (tok.Type != EndOfFile) {
      printf("{%s, %s}\n", tok.TypeStr, tok.Literal);
      tok = l.NextToken(&l);
    }
  }
}
