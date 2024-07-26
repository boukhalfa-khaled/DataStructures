#include <stdio.h>
#include <stdlib.h>

/* Linked List Implementation of the Stack
 * before using the stack define the type of the stack entry here.
*/
typedef int StackEntry;


typedef struct stackNode {
    StackEntry entry;
    struct stackNode *next;
} StackNode;
typedef struct stack{
    StackNode *top;
    int size;
}Stack;
void CreateStack(Stack *);
void Push(StackEntry , Stack *);
void Pop(StackEntry *, Stack *);
void StackTop(StackEntry *, Stack *);
int StackFull(Stack *);
int StackEmpty(Stack *);
void CleareStack(Stack *);
void TraverseStack(Stack *, void(*)(StackEntry));
int StackSize(Stack *);

