//implmenting a queue using stack
#include <stdio.h>
#include <string.h>

#define size 20
struct stack
{
	int s[size];
	int top;
};
typedef struct stack S;
struct stack  s1;

struct stack  s2;

int c1=0,c2=0;
void push(int*,char);
char pop(int*);


main()
{
	s1.top =-1;
	s2.top = -1;
	int i,j,k,l;
	int * tmp;
	char in[20];
	int el;

	
	int ch=1;
	while(ch!= 0)
	{
		printf("Enter\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit loop\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter an element to be enqueued\n");
				scanf("%d", &el);
				while(!isempty(s2))
				{
					push(s1.s, pop(s2.s));
				}
				push(s1, el);
				printf("\n%d \n", s1.s[s1.top]);
				while(!isempty(s1))
				{
					push(s2, pop(s1.s));
				}
				
				break;
			case 2:
				printf("The element deqeued is ");
				if(isempty(s2.s))
				{
					printf("undeflow\n");
					break;
				}
				
				printf("%d\n", pop(s2.s));
				break;
			case 3:
				
				printf("\n");
				break;
			case 0:
				break;


		}
	}
}




void push(int * stack,char a, int top)
{
	stack.top++;
	stack.s[stack.top]= a;
	printf("check\n");
	printf("%d\n", stack.s[stack.top]);
	
}

int isempty(top)
{
	if(top<0)
		return 1;
	else
		return 0;
}
char pop(S stack,top)
{

	char tmp;
	tmp = stack.s[stack.top];
	stack.top--;
	return tmp;
}