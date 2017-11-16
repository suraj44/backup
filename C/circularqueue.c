#include <stdio.h>
#include <math.h>
#define size 5

int q[2][size];
int head =0;
int tail=-1;

int overflow()
{
	if(tail!=-1)
	{
		if((((head>tail)&&fabs(head-tail)==1) || fabs(head-tail)==size-1) )
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
void enq(int a,int prio)
{
	if(tail==size-1)
		tail = 0;
	else
		tail++;
	q[1][tail]= a;
	q[2][tail] = prio;
}

int deq()
{
	int max = -1;
	int mpos = 0,tmp,tmp1;
	int i;
	if(tail>=head && tail <= size-1)
	{
		for(i=head;i<=tail;i++)
		{
			if( q[2][i] > max)
			{
				max = q[2][i];
				mpos = i;
			}
		}
	}
	else
	{
		for(i=head;i<=size-1;i++)
			if (q[2][i] > max)
			{
				max = q[2][i];
				mpos = i;
			}
		for(i=0;i<=tail ;i++)
			if (q[2][i] > max)
			{
				max = q[2][i];
				mpos = i;
			}
		
	}
	tmp = q[1][head];
	q[1][head] = q[1][mpos];
	q[1][mpos] = tmp;
	tmp1 = q[2][head];
	q[2][head] = q[2][mpos];
	q[2][mpos] = tmp1;
	tmp= q[1][head];
	if(head==size-1)
		head = 0;
	else
		q[1][head] = 0;
		q[2][head] = 9999;
		head++;
	return tmp;
}

int main()
{
	int i,j,k,l;

	int el,prio;

	
	int ch=1;
	while(ch!= 0)
	{
		printf("Enter\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit loop\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter an element and its priority to be enqueued\n");
				if(!overflow())
				{
					scanf("%d %d", &el,&prio );
					enq(el,prio);
				}
				else
					printf("overflow\n");
				break;
			case 2:
				printf("The element deqeued is %d\n", deq());
				break;
			case 3:
				printf("| ");
				// if(tail>=head && tail <= size-1)
				// {
				// 	for(i=head;i<=tail;i++)
				// 		printf("%d %d | ", q[1][i], q[2][i]);
				// printf("\n");
				// }
				// else
				// {
				// 	for(i=head;i<=size-1;i++)
				// 		printf("%d %d | ", q[1][i], q[2][i]);
				// 	for(i=0;i<=tail ;i++)
				// 		printf("%d %d | ", q[1][i], q[2][i]);

				// 	printf("\n");
				// }
				for(i=0;i<=size-1;i++)
				 		printf("%d %d | ", q[1][i], q[2][i]);
				 printf("\n");
				break;
			case 0:
				break;


		}
		printf("head %d tail %d\n", head, tail);
	}
	return 0;
}