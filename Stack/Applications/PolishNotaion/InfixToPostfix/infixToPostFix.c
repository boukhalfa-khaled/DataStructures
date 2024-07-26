#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



// solution:

int IsInteger(char c){
		return (c >= '0' && c <= '9');
} 
int Precedent(char op1,char op2)
{
	if(op1 == '$')
		return 1 ;
	if(op1 == '*' || op1 == '/')
		return (op2 != '$');
	if(op1 == '+' || op1 == '-')
		return (op2 != '$' && op2 != '*' && op2 != '/');
	return 0;
}
void InfixToPostfix(char infix[],char postfix[])
{
	int j = 0;
	Stack s ;
	CreateStack(&s);
	char c, op;
	for(int i = 0 ; (c = infix[i]) != '\0'; i++)
		if(IsInteger(c))
			postfix[j++] = c;
		else
		{
			if(!StackEmpty(&s))
			{
				StackTop(&op, &s);
				while(!StackEmpty(&s) && Precedent(op, c))
				{
					Pop(&op, &s);
					postfix[j++] = op;
					if(!StackEmpty(&s)) StackTop(&op, &s);
				}
			}
			Push(c, &s);
		}
	while(!StackEmpty(&s))
	{
		Pop(&op, &s);
		postfix[j++] = op;
	}
	
		postfix[j] = '\0';
}

int main()
{
	char infix[] = "1+2*3$4/5+6";
	char postfix[80];

	InfixToPostfix(infix, postfix);
    printf("infix :%s\n",infix);
    printf("postfix :%s\n",postfix);
    return 0;
}
