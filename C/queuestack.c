#include <stdio.h>
#include <string.h>
#define size 20

int stack1[size];
int stack2[size];
int top1=-1;
int top2= -1;

void push1(int);
int pop1();
void push2(int);
int pop2();

main()
{
	int i,j,k,l;
	char in[20];
	int el;

	l = strlen(in);
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
				while(!isempty1())
				{
					push2(pop1());
				}
				push2(el);
				while(!isempty2())
				{
					push1(pop2());
				}
				break;
			case 2:
				if(isempty1())
				{
					printf("underflow\n");
					break;
				}
				printf("The element deqeued is " );
				if(isempty1())
				{
					printf("underflow\n");
					break;
				}
				printf("%d \n",pop1());

				break;
			case 3:
				for(i=top1;i>=0;i--)
					printf("%d ", stack1[i]);
				printf("\n");
				break;
			case 0:
				break;


		}
	}
}

void push1(int a)
{
	top1++;
	stack1[top1]= a;

}

int pop1()
{

	int tmp;
	tmp = stack1[top1];
	top1--;
	return tmp;
}


void push2(int a)
{
	top2++;
	stack2[top2]= a;

}
int isempty1()
{
  if (top1<0)
    return 1;
  else
    return 0;
}

int isempty2()
{
  if (top2<0)
    return 1;
  else
    return 0;
}

int pop2()
{

	int tmp;
	tmp = stack2[top2];
	top2--;
	return tmp;
}
