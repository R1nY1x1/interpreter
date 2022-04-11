#include <stdio.h>
#include "repl.h"

int main(void)
{
  printf("Hello! This is the 8086 assemble language!\n");
  printf("Feel free to type in commands.\n");

  REPL();

  return 0;
}
