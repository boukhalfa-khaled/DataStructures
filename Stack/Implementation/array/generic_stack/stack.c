#include <stdio.h>
#include "stack.h"


Stack * CreateStack(int total, int type_size) 
{
   Stack *s = malloc(sizeof(Stack)); 
   s->top = 0;
   s->type_size = type_size;
   s->total = total;
   s->data = malloc(total * type_size);
   return s;
}

void Push(Stack *pStack, void *pElement)
{
    void *target = (char *) pStack->data + ((pStack->top)*pStack->type_size);
    memcpy(target, pElement,pStack->type_size);
    pStack->top++;
}

void Pop(Stack *pStack, void *pElement)
{
    void * pe = (char*) pStack->data + ((pStack->top - 1) * pStack->type_size);
    pStack->top--;
    memcpy(pElement, pe,pStack->type_size);
}

void stackTop(Stack *pStack, void *pElement)
{
    void * pe = (char*) pStack->data + ((pStack->top - 1) * pStack->type_size);
    memcpy(pElement, pe ,pStack->type_size);
}

void TraverseStack(Stack *pStack, void (*pFunction)(void *))
{
    for(int i = pStack->top-1 ; i>=0; i--)
    {
        void *element = (char *)pStack->data + (i * pStack->type_size); 
        pFunction(element);
    }
}

int StackFull(Stack *pStack)
{
    return pStack->top >= pStack->total;
}

int StackEmpty(Stack *pStack)
{
    return !pStack->top;
}

int StackSize(Stack *pStack)
{
    return pStack->top;
}

void ClearStack(Stack *pStack)
{
    free(pStack->data);
    free(pStack);
}

