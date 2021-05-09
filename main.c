#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Libs customizadas
#include "libs/utils.h"

int main (int argc, char *argv[] ){
  int typeResearch = 0;
  int sizeOfFile;

  // Verifica se o 2 argumento é falso
  if(argv[2] == NULL) {
    printf("Insira um arquivo para pesquisa");
    return 0;
  }
  
  // Recebe qual o tipo de pesquisa passada pelo usuário
  typeResearch = getTypeResearch(argv[1]);

  // Entra se o tipo de pesquisa for positivo
  if(typeResearch >= 0){

    // Pega o tamanho do arquivo passado
    sizeOfFile = sizeFile(argv[2]);
    
    // Cria um vetor com o tamanho do arquivo
    char textString[sizeOfFile];
    
    // Abre o arquivo e copia para o vetor textString
    openFile("text.txt", sizeOfFile, textString);

    puts(textString);

    printf("Contagem: %i", wordsCounter(textString));
    

  } else {
    printf("Pesquisa invalida");
  }

  system("pause");
  return 0;
}