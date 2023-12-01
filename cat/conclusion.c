#include "conclusion.h"

void Print(char *flags, int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' || strcmp(argv[i], "-") == 0 ||
        (argv[i][0] == '-' && argv[i][1] == '-') || strcmp(argv[i], "--") == 0)
      continue;
    else {
      PrintFile(argv[i], flags);
    }
  }
}

void PrintFile(char *filename, char *flags) {
  int tek, pred = '\n';
  int probelone = 0;
  int number_n = 1, number_b = 1;
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("n/a file");
  } else {
    tek = fgetc(file);
    while (tek != EOF) {
      if (strstr(flags, "s") != NULL && (tek != '\n' && pred == '\n'))
        probelone = 0;
      if (strstr(flags, "s") != NULL && (tek == '\n' && pred == '\n')) {
        if (probelone == 0)
          probelone = 1;
        else {
          pred = tek;
          tek = fgetc(file);
          continue;
        }
      }
      if (strstr(flags, "n") != NULL && strstr(flags, "b") == NULL &&
          pred == '\n') {
        printf("%6d\t", number_n);
        number_n++;
      }
      if (strstr(flags, "b") != NULL && pred == '\n' && tek != '\n') {
        printf("%6d\t", number_b);
        number_b++;
      }
      if (strstr(flags, "e") != NULL && tek == '\n') {
        printf("$");
      }
      if (strstr(flags, "v") != NULL) {
        if ((tek < 32 && tek != '\n' && tek != '\t') || tek == 127) printf("^");
        if (tek > 127 && tek < 160) printf("M-^");
        if (((tek < 32 && tek != '\n' && tek != '\t') || tek == 127) ||
            (tek > 127 && tek < 160))
          tek = tek < 32 ? tek + 64 : tek - 64;
      }
      if (strstr(flags, "t") != NULL && tek == '\t') {
        printf("^");
        tek = '\t' + 64;
      }
      putc(tek, stdout);
      pred = tek;
      tek = fgetc(file);
    }
  }
  fclose(file);
}
