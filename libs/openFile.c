#include "openFile.h"

void openFile(char *linkFile, int sizeFile, char *string){
  FILE *file;

  // Abre o arquivo passado no parâmetro e seleciona a forma de abertura, nesse
  // caso o r seria para a leiura.
  file = fopen(linkFile, "r");

  if(file == NULL){

    // Mapeia o erro obtido e imprime a mensagem de erro na saida
    perror("Erro no arquivo");
    exit(0);
  }

  memset(string, '\0', sizeFile);
  
  char text[sizeFile];

  // Faz a leitura do arquivo até que nulo
  while(fgets(text, sizeFile, file) != NULL){
    //concatena as duas strings
    strcat(string, text);
  }

  fclose(file);
}
