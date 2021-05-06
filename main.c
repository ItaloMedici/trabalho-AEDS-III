#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "libs/openFile.h"
#include "libs/sizeFile.h"

int main (int argc, char *argv[] ){

  if(argv[2] == NULL) {
    printf("Insira um arquivo para pesquisa");
    return 0;
  }

  int sizeOfFile = sizeFile(argv[2]);
  char textString[sizeOfFile];

  openFile("text.txt", sizeOfFile, textString);
  
  puts(textString);

  system("pause");
  return 0;
}