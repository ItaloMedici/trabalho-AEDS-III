#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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