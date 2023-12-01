#include "parser.h"

void FlagVoid(char *flags, int argc, char **argv, int *error_flags) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-' || strcmp(argv[i], "-") == 0 ||
        (argv[i][0] != '-' && argv[i][1] != '-') ||
        strcmp(argv[i], "--") == 0) {
      break;
    } else {
      append_flags(argv[i], flags, error_flags);
    }
  }
}

void append_flags(char *argv_flag, char *flags, int *error_flags) {
  int index = 0, indexf = 0;
  int pro = 0;
  struct str_flags flagsProv[8] = {{'e', "ev"}, {'b', "b"}, {'E', "e"},
                                   {'v', "v"},  {'n', "n"}, {'s', "s"},
                                   {'T', "t"},  {'t', "tv"}};
  for (int i = 1; i < (int)strlen(argv_flag); i++) {
    char flag = ' ';
    if (argv_flag[1] == '-') {
      strcat(flags, LongFlagsF(argv_flag));
      pro = 1;
      break;
    } else
      flag = argv_flag[i];
    for (int j = 0; j < 8; j++) {
      if (flagsProv[j].flags == flag) {
        indexf = j;
        if (strstr(flags, flagsProv[indexf].a_flags) == NULL) {
          strcat(flags, flagsProv[indexf].a_flags);
          index += strlen(flags);
        }
      }
    }
  }
  if (!pro) {
    int x = provf(argv_flag, flagsProv);
    *error_flags = x;
  }
}

int provf(char *argv_flag, struct str_flags *a) {
  int err = 0;
  int count = 0;
  for (int i = 1; i < (int)strlen(argv_flag); i++) {
    for (int j = 0; j < 8; j++) {
      if (argv_flag[i] != a[j].flags) count++;
    }
    if (count == 8) {
      err = 1;
      break;
    }
    count = 0;
  }
  return err;
}

char *LongFlagsF(char *argv_flag) {
  char long_flag[3][20] = {"--number", "--squeeze-blank", "--number-nonblank"};
  for (int i = 0; i < 3; i++) {
    if (strcmp(long_flag[i], argv_flag) == 0) {
      if (i == 0)
        return "n";
      else if (i == 1)
        return "s";
      else if (i == 2)
        return "b";
    }
  }
}
