#include<stdio.h>
#include<process.h>
#define SIZE 30
char stack[SIZE];
int top=-1;

int priority(char ch)
{
	switch(ch)
	{
		case '^':return 5;
		case '*':
		case '/':return 4;
		case '+':
		case '-':return 3;
		default : return 1;
	}
}
void push(char ch)
{
	if(top==SIZE-1)
	{
		printf("\nPush not possible. Overflow condition");
		return;	
	}	
	stack[++top]=ch;
}
char pop()
{
	if(top==-1)
	{
		printf("\nPop not possible. Underflow condition");
		return;
	}
	return stack[top--];
}
int main()
{
	int i=0,j;
	char infix[SIZE],ch;
	printf("\nEnter infix expression:");
	scanf("%s",&infix);
	while(infix[i])
	{
		switch(infix[i])
		{
			case '+':
			case '-':
			case '/':
			case '*':
			case '^':
				while(priority(infix[i])>=priority(stack[top]))
				{
					printf("%c",pop());
				}
				push(infix[i]);
				break;
			case '(':
				push(infix[i]);
				break;
			case ')':
				ch=pop();
				while(ch!='(')
				{
					printf("%c",ch);
					ch=pop();		
				}
				break;
			default:
				printf("%c",infix[i]);
				break;		
		}
		i++;
	}
	while(top>=0)
	{
		printf("%c",pop());
	}
	return 0;
}
