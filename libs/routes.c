#include "routes.h"

int structUsage = 0;

// Controla e chama as pesquisas escolhidas pelo usuário passando as palavras já tratadas
int structuresDriver(char *word, int typeOfReasearch, int totalWords) {
  // chama a repectiva estrutura de pesquisa
  switch (typeOfReasearch) {
    case 0: return sequentialSearch (word, totalWords);  
    case 1: return binarySearch(0, totalWords, word);
    case 2: return injectTree(word);
  }
}

void printDriver(int typeOfReasearch, int totalWords){
  switch (typeOfReasearch) {
    case 0:
      printSeqSearch(totalWords);
      structUsage = getSeqUsageCount();
    case 1: 
      printBinSearch(totalWords); 
      structUsage = getUsageBinCounter ();
    case 2:
      printTree(getRoot());
      structUsage = getUsegedBinTree();
  }
}

int getStructUsage() {
  return structUsage;
}