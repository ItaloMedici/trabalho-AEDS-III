#include "binTreeSearch.h"

node *root = NULL;
int usageBinTree = 0;

int initTree(node **root, stringStruct stringSt) {
  // se nulo inicializamos as folhas como nulas e o valor como
  // nossa estrutura de plavras
  if(*root = NULL){
    *root = (node*)malloc(sizeof(node));
    (*root)->value = stringSt;
    (*root)->left = NULL;
    (*root)->right = NULL;
    return 1;
  } 

  int compareResult = strcmp(stringSt.word, (*root)->value.word);

  if (compareResult == 0) {
    (*root)->value.usageCounter++;
    return 0;
  } else if (compareResult > 0) {
    usageBinTree++;
    // retorna a função passando a raiz como a folha da direita
    return initTree(&(*root)->right, stringSt);
  } else {
    usageBinTree++;
    // retorna a função passando a raiz como a folha da esquerda
    return initTree(&(*root)->left, stringSt);
  }
}

// função para inserir a palavra na estrurua de string
int injectTree(char *word) {
  stringStruct stringSt;

  // insere a palavra na estrurua
  strcpy(stringSt.word, word);
  stringSt.usageCounter = 1;

  return initTree(&root, stringSt);
}

void printTree(node *root) {
  if(root != NULL){    
    printf("%-20s\t->\t %d\n", root->value.word, root->value.usageCounter);
    printTree(root->left);
    printTree(root->right);        
  }
}

int getUsegedBinTree() {
  return usageBinTree;
}

node* getRoot() {
  return root;
}