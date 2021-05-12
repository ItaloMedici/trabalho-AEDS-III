
#define MAX_LETTERS 1024

typedef struct stringStruct {
    char word[21];
    int usageCounter;
    struct stringStruct *next;
}stringStruct;
