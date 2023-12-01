#include <stdio.h>
#include <string.h>

void main(int argc, char** argv) {
  char inputCommand[100];
  char flagsCommand[8];
  char fileName[32];

  int flags_flagsCommand = 0;

  // fgets(inputCommand, 1024, stdin);

  for (int i = 0; inputCommand[i] != '\0'; i++) {
    printf("%d", flags_flagsCommand);
    if (inputCommand[i] == '-' && flags_flagsCommand == 0) {
      int x = i;
      int countflags = 0;
      printf("%d", countflags);
      while (inputCommand[x] != ' ') {
        if (inputCommand[x] == '.') {
          strcpy(flagsCommand, "");
          break;
        } else {
          printf("%d", countflags);
          flagsCommand[countflags] = inputCommand[x];
          countflags++;
        }
        if (inputCommand[x + 1] == ' ') {
          flags_flagsCommand = 1;
        }
        x++;
      }

      i += countflags;
    }

    if (flags_flagsCommand == 1 && inputCommand[i - 1] == ' ') {
      int x = i;
      int y = 0;
      while (inputCommand[x] != '\0') {
        fileName[y] = inputCommand[x];
      }
    }
  }

  printf("%s\n%s", flagsCommand, fileName);
}
