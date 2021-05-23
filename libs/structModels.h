
typedef struct stringStruct {
    char word[20];
    int usageCounter;
    struct stringStruct *next;
} stringStruct;

typedef struct node{
    struct node *left;
    struct node *right;
    stringStruct value;
}node;