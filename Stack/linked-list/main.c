#include <stdio.h>
#include <stdlib.h>

// Start of Header file 
typedef int StackEntry;
// we don't have MAXSTACK because we're using linked-list 
// End of Header file 

typedef struct stackNode {
	StackEntry entry;
	struct stackNode *next; 
} StackNode ;

typedef struct stack{
	StackNode *top;
} Stack;

void CreatStack(Stack *ps){
	 ps->top= NULL;
}


void Push(StackEntry e  , Stack *ps){
	StackNode *pn = (StackNode*)malloc(sizeof(StackNode));	
	pn->entry = e ;
	pn->next = ps->top;
	ps->top = pn;
}

void Pop(StackEntry *pe, Stack *ps){
	*pe = ps->top->entry;
	StackNode *pn ;
	pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
}

void StackTop(StackEntry *pe, Stack *ps){
	*pe = ps->top->entry;
}

int StackFull(Stack *ps){
	return 0 ;
}
int StackEmpty(Stack *ps){
	return !ps->top;// ps->top == NULL
}

void ClearStack(Stack *ps){
	StackNode *pn = ps->top; 
	while(pn){
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
//	for(StackNode pn = ps->top ; pn ; pn = pn->next){
//		free(ps->top);
//		ps->top = pn;
//	}
}	

int StackSize(Stack *ps){
	int size;
	StackNode *pn = ps->top; 
	for(size=0 ;  pn ; pn=pn->next)
		size++;
	return size;
}


void TraverseStack(Stack *ps, void (*pf)(StackEntry)){
//	StackNode *pn = ps->top;
//	while(pn){
//		(*pf)(pn->entry);
//		pn = pn->next;
//	}
	for(StackNode *pn = ps->top; pn ; pn = pn->next)
		(*pf)(pn->entry);
}


// user function 
void display(StackEntry e){
	printf("====== : %d\n", e);
}


int main () {
	Stack s; 
	CreatStack(&s);
	printf("Stack Empty %d \n", StackEmpty(&s));
	Push(10,&s);
	Push(25,&s);
	Push(30,&s);
	Push(40,&s);
	printf("Stack Empty %d \n", StackEmpty(&s));
	printf("Stack Full %d \n", StackFull(&s));
	printf("\n===========================\n");
	TraverseStack(&s, &display);
	printf("===========================\n");
	StackEntry a ;
	StackEntry b ;
	Pop(&a, &s);
	StackTop(&b, &s);
	printf("this is the a element is poped now %d\n",a);
	printf("\n===========================\n");
	TraverseStack(&s, &display);
	printf("===========================\n");
	printf("this is the b element the last element in the stack%d\n",b);
	printf("Stack size %d\n",StackSize(&s));
	printf("the number 4 has been pushed now\n\n");
	Push(4,&s);
	printf("Stack size %d\n",StackSize(&s));
	printf("===========================\n");
	TraverseStack(&s, &display);
	printf("===========================\n");
	return 0;
}


