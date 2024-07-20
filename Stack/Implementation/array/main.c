#include <stdio.h>

/* this code will be in the Header File*/
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
    // for(int i=0; i<pStack->top; i++)
    // {
    //     pFunction(pStack->entry[i]);
    // }
    // for(int i=pStack->top; i > 0;i--)
    // {
    //     (*pFunction)(pStack->entry[i-1]);
    // }

    for(int i=pStack->top; i > 0;i--)
    {
         pFunction(pStack->entry[i-1]);
    }
}
/*  SIMPLE MAIN PROGRAM FOR TEST */
// User Function for Display elements in the stack
void display (StackEntry e){
    printf("---> %d\n",e);
}


// StackTop created by the user if the implementer does not provide one

void User_StackTop(StackEntry *pEntry, Stack *pStack)
{
    Pop(pEntry, pStack);
    Push(*pEntry, pStack);
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
