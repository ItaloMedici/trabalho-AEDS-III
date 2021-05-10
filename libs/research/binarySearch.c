#include "binarySearch.h"

int binarySearch(char *string, char *word){
    int min = 0;
    int max = wordsCounter(string) - 1;
    int counter = 0;
    int guess = 0;

    while (max >= min) {
        guess = floor((max + min) / 2);
        if (strcmp(string[guess], word) == 0) {
            counter++;
            return counter;
        } else if (strcmp(string[guess], word) < 0) {
            min = guess + 1; 
        } else {
            max = guess - 1;
        }
    }

    return 0;
}