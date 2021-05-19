#include"sort.h"

// Função para ordernas as plavras
void sort(char *string) {

  int count = wordsCounter(string);
  char copyString[count][21];
  char *word = NULL;
  char tmp[20];
  
  // faz uma copia da string para uma matriz
  word = strtok(string, " 1234567890,.;/´`!?@#$¨&*()-_|\"\n\t");
  for (int i=0; word != NULL; i++){
    
    if(strlen(word) <= 21){
      strcpy(copyString[i], word);
    }

    word = strtok(NULL, " 1234567890,.;/´`!?@#$¨&*()-_|\"\n\t");
  }

 // ordena as palavras 
  for(int i = 0; i < count; i++){
    for(int j = i + 1; j < count; j++){
      if(strcmp(copyString[j], copyString[i]) < 0){
        strcpy(tmp, copyString[i]);
        strcpy(copyString[i], copyString[j]);
        strcpy(copyString[j], tmp);
      }
    }
  }

  // concaneta as palvras já ordenas novamente para a string
  strcpy(string, NULL);
  for(int i = 0; i < count; i++){
    strcat(string, copyString[i]);
    strcat(string, " ");
  }
  
  free(word);
}