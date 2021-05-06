#include "sizeFile.h"

int sizeFile(char *linkFile){
  int length;

  FILE *file = fopen(linkFile, "r");

  if(file == NULL){
    perror("Erro no arquivo");
    exit(0);
  }

  // reposiciona o indicador de posição do fluxo (arquivo)  
  // em função do deslocamento, nesse caso para o final (SEEK_END).
  fseek(file, 0, SEEK_END);

  // retorna o valor do indicador de posução do fluxo (arquivo)
  length = ftell(file);
  fclose(file);

  return length;
}