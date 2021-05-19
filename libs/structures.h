
// máximo de palavras únicas aceitas
#define MAX_WORDS 300

typedef struct stringStruct {
    char word[21];
    int usageCounter;
    struct stringStruct *next;
}stringStruct;
