#ifndef _strtonum_H
#define _strtonum_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

int getNumber(char  **str);
int getnum(const char *str);
int strcmpInsensitive(char* a, char* b);
int loop(char **str);
int getAdress(long int val);
int getCharacter(char **str);
#endif // _strtonum_H
