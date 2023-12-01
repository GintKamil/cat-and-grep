#include <stdio.h>
#include <string.h>

struct str_flags {
  char flags;
  char *a_flags;
};

void FlagVoid(char *flags, int argc, char **argv, int *error_flags);
void append_flags(char *argv_flag, char *flags, int *error_flags);
int provf(char *argv_flag, struct str_flags *a);
char *LongFlagsF(char *argv_flag);
