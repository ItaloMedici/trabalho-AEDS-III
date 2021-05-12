#include "binarySearch.h"

// Estrutura de strings 
stringStruct *binStringStruct[MAX_LETTERS];

// Variável global de contagem de uso da estrurura
int usageBinCounter = 0;

int binarySearch(int min, int max, char *word){
    // variável de chute, que será a posição media do vetor
    int guess;

    // Equando o maior valor for maior ou igual ao menor
    while (max >= min) {

        // Pega a media entre o maior tamanho da estrurura e o menor tamanho
        guess = floor((max + min) / 2);

        // Compara se a palavra da estrurua é igual a palavra passada
        if (strcmp(binStringStruct[guess]->word, word) == 0) {

            // Soma o contador dessa palavra 
            binStringStruct[guess]->usageCounter++;

            return 0;
        } 
        else if (strcmp(binStringStruct[guess]->word, word) < 0) {
            min = guess + 1;

            // Soma o contador de uso da estrura
            usageBinCounter++;

            // chama a função novamente 
            return binarySearch(min, max, word);
        }    
        else {
            max = guess - 1;
            usageBinCounter++;
            
            // chama a função novamente 
            return binarySearch(min, max, word);
        }
    }

    // chama a função de inserir a palavra quando não achamos
    return binInjection(word);
}

int binInjection(char *word) {

    int position = getUnicWords();

    // aloca o espaço da palavra
    binStringStruct[position] = (stringStruct *) malloc(sizeof(stringStruct));
    
    // verifica se está nulo
    if(binStringStruct[position] == NULL){
        printf("Error");
        exit(0);
    }

    // copia a palavra para e estrutura
    strcpy(binStringStruct[position]->word, word);
    binStringStruct[position]->usageCounter = 1;
    binStringStruct[position]->next = NULL;

    return 1;
}

// função para retornar a contagem de uso da estrurura
int getUsageBinCounter (){
    return usageBinCounter;
}

// Função para impimir a estrutura
void printBinSearch(int wordsCount){
    int i;
    for(i=0; i<wordsCount; i++){
        pritnf("\n%-20s\t->\t%d", binStringStruct[i]->word, binStringStruct[i]->usageCounter);
    }
}

