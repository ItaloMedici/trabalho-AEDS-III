#include "separator.h"

int unicWords = 0;
int totalWords = 0;

int splitter(char *string, int typeOfResearch){

    // Total geral de palavras 
    totalWords = wordsCounter(string);

    char *currentWord = NULL;
    char *nextWord = NULL;

    currentWord = strtok(string, " ");
    
    while(currentWord != NULL) {
        if(unicWords < MAX_WORDS || strcmp(currentWord, nextWord) == 0) {
            nextWord = strdup(currentWord);

            /*Chamamos a função de de controle de estrutura passando a palaavra atual 
            e a contagem atual de palavras únicas, rerornando 1 e chama seu respectivo
            tipo de pesquisa
            */
            unicWords += structuresDriver(currentWord, typeOfResearch, unicWords);
        }
        currentWord = strtok(NULL, " ");
    }

    // Após tratarmos com nossa pesquisa chamos a sua respectiva função de imprimir
    printDriver(typeOfResearch, unicWords);

    currentWord = NULL;
    nextWord = NULL;
}

int getUnicWords() {
    return unicWords;
}
