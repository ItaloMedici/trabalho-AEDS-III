#ifndef _UTILS
#define _UTILS

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "structModels.h"

#define MAX_WORDS 300

void openFile(char *linkFile, int sizeFile, char *string);
int sizeFile(char *linkFile);
int getTypeResearch(char *research);
int wordsCounter (char *string);

void sort(char *string);

/*
 gcc -o main main.c libs/sequentialSearch.c  libs/binarySearch.c libs/separator.c libs/utils.c libs/routes.c
*/

#endif