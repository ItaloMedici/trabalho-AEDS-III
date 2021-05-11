#include "binarySearch.h"

stringStruct *string[MAX_LETTERS];

int binarySearch(int max, int min, char *word){
    int counter = 0;
    int guess;

    while (max >= min) {
        guess = floor((max + min) / 2);

        if (strcmp(string[guess]->word, word) == 0) {
            string[guess]->usedCounter++;

            return 0;
        } 
        else if (strcmp(string[guess]->word, word) < 0) {
            min = guess + 1;

            return binarySearch(max, min, word);
        }    
        else {  
            max = guess - 1;
            return binarySearch(max, min, word);
        }
    }

    return counter;
}

int wordInjection(char *word) {
    
    
}