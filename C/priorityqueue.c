#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 5
int arr[size];
int head=0;
int tail=0;
int count =0;


int overflow(int arr[])
{
	if(count==size-1)
		return 1;
	else
		return 0;
}

int underflow(int arr[])
{
	if(count==0)
		return 1;
	else
		return 0;
}
void en(int el)
{
	if(tail==size-2)
		tail = 0;
	arr[tail] = el;
	tail+=1;
	count++;

}

int de(int arr[])
{
	int i,tmp;
	if(tail>=head)
	{
		for(i=head; i<tail;i++)
		{
			if(arr[i]>arr[head])
			{
				tmp == arr[i];
				arr[i] = arr[head];
				arr[head] = tmp;
			}
		}
		printf("\n");
	}
	else
	{
		for(i=head;i<size-1;i++)
		{
			if(arr[i]>arr[head])
			{
				tmp == arr[i];
				arr[i] = arr[head];
				arr[head] = tmp;
			}
		}
		for(i=tail;i<head;i++)
		{
			if(arr[i]>arr[head])
			{
				tmp == arr[i];
				arr[i] = arr[head];
				arr[head] = tmp;
			}
		}
	}
	tmp = arr[head];
	if(head==size-2)
		head = 0;
	else 
		head++;
	count--;
	return tmp;
}

void print(int arr[])
{
	int i;
	if(tail>=head)
	{
		for(i=head; i< tail;i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	else
	{
		for(i=head;i<size-1;i++)
		{
			printf("%d", arr[i]);
		}
		for(i=tail;i<head;i++)
		{
			printf("%d", arr[i]);
		}
	}
	printf("\n");
}

int main()
{
	int i,j,tmp,ch;
	while(1)
	{
		printf("Enter\n 1.Enqueue\n2.Dequeue\n3. Display\n0.Exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			
			case 1:
				if(!overflow(arr))
				{
					printf("Enter element\n");
					scanf("%d", &tmp);
					en(tmp);
					print(arr);
				}
				else
				{
					printf("overflow\n");
				}
				break;
			case 2:
				if(!underflow(arr))
				{
					printf("The element dequeued is %d\n",de(arr));
					
				}
				else
					printf("underflow");
				break;
			case 3:
				print(arr);
				break;
			case 0:
				exit(0);
				break;
		}
	}
	return 0;
}