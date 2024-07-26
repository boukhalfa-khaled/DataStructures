#include <stdio.h>
#include "stack.h"


void CreateStack(Stack *pStack)
{
    pStack->top=0; 
}

void Push(StackEntry e, Stack *pStack)
{
    pStack->entry[pStack->top++] = e;
}

int StackFull(Stack *pStack)
{
    return pStack->top >= MAXSTACK;
}

int StackEmpty(Stack *pStack)
{
    return !pStack->top;
}

void Pop(StackEntry *pe, Stack *pStack)
{
    *pe= pStack->entry[--pStack->top];
}

void StackTop(StackEntry *pe, Stack *pStack)
{
    *pe = pStack->entry[pStack->top-1];
}

int StackSize(Stack *pStack){
    return pStack->top;
}

void ClearStack(Stack *pStack)
{
    pStack->top=0;
}

void TraverseStack(Stack *pStack, void (*pFunction)(StackEntry))
{
    for(int i=pStack->top; i > 0;i--){
         pFunction(pStack->entry[i-1]);
    }
}
