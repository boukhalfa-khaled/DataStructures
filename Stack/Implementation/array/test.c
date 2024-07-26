#include <stdio.h>
#include "stack.h"

// User Function for Display elements in the stack
void display (StackEntry e){
    printf("---> %d\n",e);
}


/*
 * StackTop created by the user if the implementer
 * does not provide one
*/
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
