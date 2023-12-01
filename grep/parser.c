#include "parser.h"

void FlagVoid(char *flags, int argc, char **argv, int *error_flags) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-' || strcmp(argv[i], "-") == 0) {
      break;
    } else {
      append_flags(argv[i], flags, error_flags);
    }
  }
}

void append_flags(char *argv_flag, char *flags, int *error_flags) {
  int index = 0, indexf = 0;
  int pro = 0;
  struct str_flags flagsProv[10] = {
      {'e', "e"}, {'i', "i"}, {'v', "v"}, {'c', "c"}, {'l', "l"},
      {'n', "n"}, {'h', "h"}, {'s', "s"}, {'f', "f"}, {'o', "o"}};
  for (int i = 1; i < (int)strlen(argv_flag); i++) {
    char flag = ' ';
    flag = argv_flag[i];
    for (int j = 0; j < 10; j++) {
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
    for (int j = 0; j < 10; j++) {
      if (argv_flag[i] != a[j].flags) count++;
    }
    if (count == 10) {
      err = 1;
      break;
    }
    count = 0;
  }
  return err;
}

char *WordSearch(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    if ((argv[i - 1][0] == '-' || strcmp(argv[i - 1], "-") == 0) ||
        (strcmp(argv[i - 1], "./s21_grep") == 0 && argv[i][0] != '-')) {
      return argv[i];
    }
  }
  return " ";
}
