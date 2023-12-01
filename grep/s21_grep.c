#include <stdio.h>

#include "conclusion.h"
#include "parser.h"

int main(int argc, char** argv) {
  char flagsCommand[8] = "\0";
  int error_flags = 0;
  FlagVoid(flagsCommand, argc, argv, &error_flags);
  char* poisk = WordSearch(argc, argv);
  if (error_flags == 0)
    Print(flagsCommand, argc, argv, poisk);
  else
    printf("No option");
  return 0;
}
