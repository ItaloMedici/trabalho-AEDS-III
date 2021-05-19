#include "utils.h"

// Função para abrir o arquivo e retornar seu texto tratado
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

  // trata as palavras alfabeticamente lidas no arquivo
  sort(string);
}

// retorna o tamanho do arquivo
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

// retorna o tipo da pesquisa passado
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

// contador de palavras (também repetidas)
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

    // avança a checagem para a proxima palavra
    words = strtok(NULL, " 1234567890,.;/´`!?@#$¨&*()-_|\"\n\t");
  }

  // Libera os espaços alocados
  free(copy);
  free(words);

  copy = NULL;
  words = NULL;

  return counter;
}


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