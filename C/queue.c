#include <stdio.h>
#include <stdlib.h>
#define size 10
int arr[size];
int head=0;
int tail=0;


void en(int el)
{
	if(tail == size-1)
	{
		printf("Overflow\n");
		return;
	}

	arr[tail] = el;
	tail+=1;

}

void de()
{
	if(head == tail)
	{
		printf("Underflow\n");
		return;
	}
	head+=1;
}

void print()
{
	int i;
	for(i=head; i< tail;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

main()
{
	int i,j,tmp,ch;
	while(1)
	{
		printf("Enter\n 1.Enqueue\n2.Dequeue\n3.Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			
			case 1:
				printf("Enter element\n");
				scanf("%d", &tmp);
				en(tmp);
				print();
				break;
			case 2:
				de();
				print();
				break;
			case 3:
				exit(0);
				break;
		}
	}
}