#include "conclusion.h"

void Print(char *flags, int argc, char **argv, char *poisk) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' || strcmp(argv[i], "-") == 0 ||
        strcmp(argv[i], poisk) == 0)
      continue;
    else {
      if (strstr(flags, "f") != NULL) {
        poisk = FileFlagF(argc, argv);
        PrintFile(argv[i], flags, poisk, CountFileOpen(argc, argv, poisk));
      } else
        PrintFile(argv[i], flags, poisk, CountFileOpen(argc, argv, poisk));
    }
  }
}

void PrintFile(char *filename, char *flags, char *poisk, int countFile) {
  char tek[1024];
  int number = 1, count = 0, pro_l = 0;
  FILE *file = fopen(filename, "r");
  if (file == NULL && strstr(flags, "s") == NULL)
    printf("n/a file");
  else if (file == NULL && strstr(flags, "s") != NULL)
    printf("%c", '\0');
  else {
    while ((fgets(tek, 1024, file)) != NULL) {
      FlagsOutput(tek, flags, poisk, filename, countFile, &number);

      if (strstr(flags, "c") != NULL && strstr(tek, poisk) != NULL) {
        count++;
      }

      if (strstr(flags, "n") != NULL) {
        if (strstr(tek, poisk) != NULL)
          Printf(tek, filename, countFile, 'n', number);
        number++;
      }

      if (strstr(flags, "l") != NULL && pro_l == 0 &&
          strstr(tek, poisk) != NULL) {
        pro_l = 1;
      }
    }
    if (pro_l == 1) printf("%s\n", filename);
    if (strstr(flags, "c") != NULL && countFile <= 1)
      printf("%d\n", count);
    else if (strstr(flags, "c") != NULL && countFile > 1)
      printf("%s:%d\n", filename, count);
  }
  fclose(file);
}

void FlagsOutput(char *tek, char *flags, char *poisk, char *filename,
                 int countFile, int *number) {
  if ((strstr(flags, "e") != NULL || strlen(flags) == 0 ||
       strstr(flags, "s")) &&
      strstr(tek, poisk) != NULL) {
    Printf(tek, filename, countFile, 'e', 0);
  }

  if (strstr(flags, "i") != NULL) {
    char p[strlen(tek) + 1];
    for (int i = 0; i < (int)strlen(p); i++) {
      if ('A' <= tek[i] && tek[i] <= 'Z')
        p[i] = tek[i] + 32;
      else
        p[i] = tek[i];
    }
    if (strstr(p, poisk) != NULL) Printf(tek, filename, countFile, 'i', 0);
  }

  if (strstr(flags, "v") != NULL && strstr(tek, poisk) == NULL) {
    Printf(tek, filename, countFile, 'v', 0);
  }

  if (strstr(flags, "h") != NULL && strstr(tek, poisk) != NULL) {
    Printf(tek, filename, 1, 'h', *number);
  }

  if (strstr(flags, "o") != NULL && strstr(tek, poisk) != NULL) {
    Printf(poisk, filename, countFile, 'o', 0);
    printf("\n");
  }

  if (strstr(flags, "f") != NULL) {
    if (FlagF(poisk, tek) == 1) Printf(tek, filename, countFile, 'f', 0);
  }
}

int CountFileOpen(int argc, char **argv, char *poisk) {
  int count = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' || strcmp(argv[i], "-") == 0 ||
        strcmp(argv[i], poisk) == 0)
      continue;
    else {
      count++;
    }
  }
  return count;
}

void Printf(char *tek, char *filename, int countFile, char flag, int count) {
  if (countFile > 1) printf("%s:", filename);
  if (flag == 'n') printf("%d:", count);
  printf("%s", tek);
}

int RegularFlagF(char *tek, char *poisk) {
  regex_t preg;
  int err, regerr;
  err = regcomp(&preg, poisk, REG_EXTENDED);
  if (err != 0) {
    return 0;
  }

  regmatch_t pm;
  regerr = regexec(&preg, tek, 0, &pm, 0);
  regfree(&preg);
  if (regerr == 0)
    return 1;
  else {
    return 0;
  }
}

char *FileFlagF(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    if (argv[i - 1][0] == '-' || strcmp(argv[i - 1], "-") == 0) {
      return argv[i];
    }
  }
  return "\0";
}

int FlagF(char *filename, char *tek) {
  int found = 0;
  char p[100];
  FILE *f = fopen(filename, "r");
  if (f == NULL)
    return 0;
  else {
    while ((fgets(p, 100, f)) != NULL) {
      if (p[strlen(p) - 1] == '\n') p[strlen(p) - 1] = '\0';
      if (RegularFlagF(tek, p) == 1) {
        found = 1;
      }
    }
    fclose(f);
    return found;
  }
}
