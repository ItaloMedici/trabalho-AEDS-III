#include "struturesControl.h"

int structUsage = 0;

// Controla e chama as pesquisas escolhidas pelo usuário passando as palavras já tratadas
int structuresControl(char *word, int typeOfReasearch, int totalWords) {
  switch (typeOfReasearch) {
    // chama a repectiva estrutura de pesquisa
    case 0:
      return sequentialSearch (word, totalWords);  
    case 1:
      return binarySearch(0, totalWords, word);
  }
}

void printCall(int typeOfReasearch, int totalWords){
  switch (typeOfReasearch) {
    case 0:
     printBinSearch(totalWords);
     structUsage = getSeqUsageCount();
    case 1: 
      printBinSearc(totalWords); 
      structUsage = getUsageBinCounter ();
  }
}

int getStructUsage() {
  return structUsage;
}