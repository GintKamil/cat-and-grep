#include <regex.h>
#include <stdio.h>
#include <string.h>

void Print(char *flags, int argc, char **argv, char *poisk);
void PrintFile(char *filename, char *flags, char *poisk, int countFile);
void FlagsOutput(char *tek, char *flags, char *poisk, char *filename,
                 int countFile, int *number);
int CountFileOpen(int argc, char **argv, char *poisk);
void Printf(char *tek, char *filename, int countFile, char flag, int count);
int RegularFlagF(char *tek, char *poisk);
char *FileFlagF(int argc, char **argv);
int FlagF(char *filename, char *tek);
