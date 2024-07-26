#include <stdio.h>

/* Array Implementation of the Stack
 * before using the stack define the size of the stack
 * and the type of the stack entry here.
*/
#define MAXSTACK 7
typedef int StackEntry;




typedef struct stack{
    int top;
    StackEntry entry[MAXSTACK];
} Stack;
void CreateStack(Stack *);
void Push(StackEntry , Stack *);
int StackFull(Stack *);
int StackEmpty(Stack *);
void Pop(StackEntry *, Stack *);
void StackTop(StackEntry *, Stack *);
int StackSize(Stack *);
void ClearStack(Stack *);
void TraverseStack(Stack *, void (*)(StackEntry));
