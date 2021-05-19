#include "sequentialSearch.h"

stringStruct *sequentialStruct[MAX_WORDS];

int usageSeqCounter = 0;

int sequentialSearch (char *word, int totalWord) {

  if (totalWord == 0) injectSeq(word);

  for(int i = 0; i<totalWord; i++) {
    usageSeqCounter++;
    if(strcmp(sequentialStruct[i]->word, word) == 0){
      sequentialStruct[i]->usageCounter++;
      return 0;
    }
  }
  return injectSeq(word);
}

int injectSeq(char *word) {
  
    int position = getUnicWords();

    // aloca o espaço da palavra
    sequentialStruct[position] = (stringStruct *) malloc(sizeof(stringStruct));
    
    // verifica se está nulo
    if(sequentialStruct[position] == NULL){
        printf("Error");
        exit(0);
    }

    // copia a palavra para e estrutura
    strcpy(sequentialStruct[position]->word, word);
    sequentialStruct[position]->usageCounter = 1;

    return 1;
}

// Função para impimir a estrutura
void printBinSearch(int wordsCount){
    for(int i=0; i<wordsCount; i++){
        pritnf("\n%-20s\t->\t%d", sequentialStruct[i]->word, sequentialStruct[i]->usageCounter);
    }
}

int getSeqUsageCount() {
  return usageSeqCounter;
}