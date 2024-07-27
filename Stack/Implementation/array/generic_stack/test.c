#include <stdio.h>
#include "stack.h"

// User Function for Display elements in the stack
void display(void *pElement){
    int element = *(int *) pElement; 
    printf("-----> %d\n", element);
}


int main(){
    Stack *s = CreateStack(10, sizeof(int));
    int a = 5; 
    int b = 15; 
    Push(s, &a);
    Push(s, &b);
    int c,d,e;
    stackTop(s, &e);
    printf("StackSize before pop %d\n", StackSize(s));
    TraverseStack(s, &display);
    Pop(s, &c);
    Pop(s, &d);
    printf("e: stackTop %d\n", c);
    printf("StackFull %d\n", StackFull(s));
    printf("StackEmpty %d\n", StackEmpty(s));
    printf("c: %d\n", c);
    printf("d: %d\n", d);
    printf("StackSize after pop %d\n", StackSize(s));
    return 0;
}
