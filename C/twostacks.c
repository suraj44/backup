#include <stdio.h>
#include <string.h>
#define size 10

int stack[size];
int top1=-1;
int top2= size;

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
		printf("1.Push into first stack\n2.Push into second stack\n3.Pop from first stack\n4.Pop from second stack\n5.Display stack 1\n6. Display stack 2\n0.Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				if(!overflow())
				{	
					printf("Enter an element to be pushed to first stack\n");
					scanf("%d", &el);
					push1(el);
				}
				else
					printf("overflow\n");
				break;				
				
			case 2:
				if(!overflow())
				{	
					printf("Enter an element to be pushed to second stack\n");
					scanf("%d", &el);
					push2(el);
				}
				else
					printf("overflow\n");
				break;
				
			case 3:
				if(isempty1())
				{
					printf("underflow\n");
					break;
				}
				printf("The element popped is " );
				printf("%d \n",pop1());
				printf("\n");
				break;
			case 4:
				if(isempty2())
				{
					printf("underflow\n");
					break;
				}
				printf("The element popped is " );
				printf("%d \n",pop2());
				printf("\n");
				break;
			case 5:
				for(i = top1; i>=0;i--)
				{
					printf("%d ", stack[i]);
				}
				printf("\n");
				break;
			case 6:
				for(i = top2; i<=size-1;i++)
				{
					printf("%d ", stack[i]);
				}
				printf("\n");
				break;
			case 0:
				break;


		}
	}
}




int overflow()
{
	if(top2-top1==1)
		return 1;
	else
		return 0; 
}


void push1(int a)
{
	top1++;
	stack[top1]= a;

}

int pop1()
{

	int tmp;
	tmp = stack[top1];
	top1--;
	return tmp;
}


void push2(int a)
{
	top2--;
	stack[top2]= a;

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
  if (top2>size-1)
    return 1;
  else
    return 0;
}

int pop2()
{

	int tmp;
	tmp = stack[top2];
	top2++;
	return tmp;
}