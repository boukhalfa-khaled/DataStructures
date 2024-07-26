#include  "stack.h"

void CreateStack(Stack *pStack){
    pStack->top =  NULL;
    pStack->size=  0;

}
void Push(StackEntry e, Stack *pStack)
{
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    pn->entry = e ;
    pn->next = pStack->top;
    pStack->top = pn;
    pStack->size++;
}

void Pop(StackEntry *pe, Stack *pStack)
{
    StackNode *pn;
    *pe = pStack->top->entry;
    pn =  pStack->top;
    pStack->top = pStack->top->next;
    free(pn);
    pStack->size--;
}


void StackTop(StackEntry *pe, Stack *pStack)
{
    *pe = pStack->top->entry;
}

int StackFull(Stack *pStack)
{
    return 0;
}

int StackEmpty(Stack *pStack)
{
    return !pStack->top;
}

void CleareStack(Stack *pStack)
{
    StackNode *pn = pStack->top;
    //while(pn)
    while(pStack->top)
    {
        pn= pn->next;
        free(pStack->top);
        pStack->top = pn;
    }
    pStack->size = 0 ;
}


void TraverseStack(Stack *pStack, void(*pfunction)(StackEntry))
{
    for(StackNode *pn = pStack->top; pn; pn = pn->next )
        (*pfunction)(pn->entry);
}

int StackSize(Stack *pStack) 
{
    return pStack->size;
}
