#include "sequentialSearch.h"
#include "separator.h"

stringStruct *seqStruct[MAX_WORDS];

int usageSeqCounter = 0;

int sequentialSearch (char *word, int totalWord) {

  if (totalWord == 0) return injectSeq(word);

  for(int i = 0; i<totalWord; i++) {
    usageSeqCounter++;
    if(strcmp(seqStruct[i]->word, word) == 0){
      seqStruct[i]->usageCounter++;
      return 0;
    }
  }
  return injectSeq(word);
}

int injectSeq(char *word) {
  
    int position = getUnicWords();

    // aloca o espaço da palavra
    seqStruct[position] = (stringStruct *) malloc(sizeof(stringStruct));
    
    // verifica se está nulo
    if(seqStruct[position] == NULL){
        printf("Error");
        exit(0);
    }

    // copia a palavra para e estrutura
    strcpy(seqStruct[position]->word, word);
    seqStruct[position]->usageCounter = 1;

    return 1;
}

// Função para impimir a estrutura
void printSeqSearch(int wordsCount){
  for(int i=0; i<wordsCount; i++){
    printf("\n%-20s\t->\t%d", seqStruct[i]->word, seqStruct[i]->usageCounter);
  }
}

int getSeqUsageCount() {
  return usageSeqCounter;
}