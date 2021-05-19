#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Libs customizadas
#include "libs/utils.h"
#include "libs/separator.h"

int main (int argc, char *argv[] ){
  int typeResearch = 0;
  int sizeOfFile;

  // Verifica se o 2 argumento existe
  if(argv[2] == NULL) {
    printf("Insira um arquivo para pesquisa");
    return 0;
  }

  //Variável para calcular tempo de execução
  clock_t time;

  //Atribui o valor inicial de execução
  time = clock();

  // Nomes dos tipos de pesquisa, usaremos para imprimir.
  char namesResearch[][30] = {
    "Pesquisa Sequencial",
    "Pesquisa Binaria",
    "Arvore Binaria",
    "Hash Aberto",
    "Hash Lista"
  };
  
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

    printf("\n\tPALAVRA\t->\tFREQUENCIA\n\n");

   /* atraves da função splitter conseguimos:
    - Chamar a devida estrutura
    - Tratar a string   
    - Imprmir as palavras e sua frequencia atraves da pesquisa escolhida
    */
    splitter(textString, typeResearch);

    //Encerra o tempo de execução
    time = clock() - time;
        

    printf("\n\n\tINFO");
    printf("\n\nPalavras Unicas: %d", getUnicWords());
    printf("\nTipo de pesquisa: %s", namesResearch[typeResearch]);
    printf("\nTempo de execução: %g ms", (double) time );

  } else {
    printf("Pesquisa invalida");
  }

  system("pause");
  return 0;
}