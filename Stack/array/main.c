#include <stdio.h>

/* Header File start */
#define MAXSTACK 7
typedef int StackEntry;
/* Header File end*/

typedef struct stack{
    int top;
    StackEntry entry[MAXSTACK];
} Stack;

void CreateStack(Stack *pStack){
    pStack->top=0; 
}
void Push(StackEntry e, Stack *pStack){
    pStack->entry[pStack->top] = e;
    pStack->top++;
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
    pStack->top--;
    *pe= pStack->entry[pStack->top];
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
    for(int i=0; i<pStack->top; i++)
    {
        pFunction(pStack->entry[i]);
    }
}
/*  SIMPLE MAIN PROGRAM FOR TEST */
// User Function for Display elements in the stack
void display (StackEntry e){
    printf("---> %d\n",e);
}

int main(){
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
    Pop(&a, &s);
    StackTop(&b, &s);
    Push(4, &s);
    printf("this is the a element is poped now %d\n", a);
    printf("this is the b element the last element in the Stack %d\n", b);
    Push(4, &s);
    printf("i just push 4 to the stack\n");
    printf("Stack Size %d\n", StackSize(&s));
    TraverseStack(&s, &display);
    return 0;
}
