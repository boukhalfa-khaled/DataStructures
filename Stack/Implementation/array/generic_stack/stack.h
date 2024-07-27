#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    int type_size;
    int total;
    void * data;
    int top;
} Stack;

Stack * CreateStack(int total, int type_size);
void Push(Stack *pStack, void *pElement);
void Pop(Stack *pStack, void *pElement);
void stackTop(Stack *pStack, void *pElement);
void TraverseStack(Stack *pStack, void (*pFunction)(void *));
int StackFull(Stack *pStack);
int StackEmpty(Stack *pStack);
int StackSize(Stack *pStack);
