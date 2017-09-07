#include <stdio.h>
#include <stdlib.h>
struct STACK
{
	int stk[100];
	int top;
};

typedef struct STACK stack;
stack s;
void push(void);
int pop(void);
void display(void);
void peek(void);
main()
{
	int ch;
	int i,j,tmp;
	s.top = -1;

	while(1)
	{
		printf("Enter: \n1. to Push\n2.to Pop\n3.to Peek\n4.to Exit");
		scanf("%d", ch);
		switch(ch)
		{
			case 1:
				push();
				display();
				break;

			case 2:
				pop();
				display();
				break;
			case 3:
				printf("The top is %d\n", s.stk[s.top]);
				break;
			
			case 4:
				exit(0);
				break;					
		}
	}	
}

void push()
{
	int num;
	if(s.top==100-1)
	{
		printf("The stack is full\n");
		return;
	}
	else
	{
		printf("Enter element to be pushed\n");
		scanf("%d", &num);
		s.top+= 1;
		s.stk[s.top]= num;

	}
	return;
}

int pop()
{
	int num;
	if(s.top==-1)
	{
		printf("Stack is empty\n");
		return(s.top);
	}
	else
	{
	num = s.stk[s.top];
	printf("%d is popped out of the stack\n", num);
	s.top -=1;
	
	return(num)
}
}

void display()
{
	int i;
	if(s.top==-1)
	{
		printf("the stack is empty\n");
		return;
	}
	else
	{
		for(i=s.top;i>=0;i--)
		{
			printf("%d ", s.stk[s.top];)
		}
		printf("\n");
	}
}