#ifndef _strtonum_H
#define _strtonum_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>

int getNumber(char  **str);
int getnum(const char *str);
int loop(char **str);
#endif // _strtonum_H
