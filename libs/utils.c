#include "utils.h"

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

int getTypeResearch(char *research){
  int type = -1;

  // Compara a pesquisa obtida pelo usuário com os nomes das pesquisas,
  // Se forem iguais, retorna o inteiro do seu respectivo tipo
  if(strcmp(research, "pseq") == 0) type = 0;
  if(strcmp(research, "pbin") == 0) type = 1;
  if(strcmp(research, "arvore") == 0) type = 2;
  if(strcmp(research, "hashab") == 0) type = 3;
  if(strcmp(research, "hashlista") == 0) type = 4;

  return type;
}

int wordsCounter(char *string) {

  char *copy;
  char *words;
  int counter = 0;

  // Faz uma copia do texto
  copy = strdup(string);
  
  // Remove todo tipo de caractere passado no segundo parâmetro
  words = strtok(copy, " 1234567890,.;/´`!?@#$¨&*()-_|\"\n\t");

  while(words != NULL) {

    if(strlen(words) <= 20) {
      counter++;
    }

    words = strtok(NULL, " 1234567890,.;/´`!?@#$¨&*()-_|\"\n\t");
  }

  // Libera os espaços alocados
  free(copy);
  free(words);

  copy = NULL;
  words = NULL;

  return counter;
}