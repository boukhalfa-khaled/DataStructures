#include <stdio.h>
#include <stdlib.h>

/* Start of Header File */
typedef int StackEntry;
/* Start of Header File */


typedef struct stackNode {
    StackEntry entry;
    struct stackNode *next;
} StackNode;

typedef struct stack{
    StackNode *top;
    int size;
}Stack;

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

/* USER TEST */


void display (StackEntry e){
    printf("---> %d\n",e);
}


void User_StackTop(StackEntry *pEntry, Stack *pStack)
{
    Pop(pEntry, pStack);
    Push(*pEntry, pStack);
}



int main()
{
    Stack s;
    CreateStack(&s);
    Push(10,&s);
    Push(20,&s);
    Push(30,&s);
    printf("Stack Empty %d\n", StackEmpty(&s));
    printf("Stack Full %d\n", StackFull(&s));
    TraverseStack(&s, &display);
    printf("\n\n\n");
    StackEntry a;
    StackEntry b;
    StackEntry c;
    Pop(&a, &s);
    StackTop(&b, &s);
    User_StackTop(&c, &s);
    printf("this is the a element is poped now %d\n", a);
    printf("this is the b element the last element in the Stack using implementer stack top %d\n", b);
    printf("this is the c element the last element in the Stack using User STack ToP %d\n", c);
    Push(4, &s);
    printf("i just push 4 to the stack\n");
    printf("Stack Size %d\n", StackSize(&s));
    TraverseStack(&s, &display);
    return 0;

}
