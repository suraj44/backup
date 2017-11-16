#include <stdio.h>
#define declare {int i,j,n,ch,tmp, arr[20];}
#include <stdlib.h>
;
struct N
{
	int val;
	struct N * head;
	struct N * next;
};

typedef struct N node;



int main(int argc, char const *argv[])
{
	int i,j,n,ch,tmp, arr[20];
	node * temp,*curr;
	printf("Enter the number of nodes in the undirected graph\n");
	scanf("%d", &n);
	node * master =(node*)malloc(sizeof(node));;
	for(i=0;i<n;i++)
	{
		printf("Enter the neighbours of vertex %d. Enter 99 to stop\n", i+1);
		master->head->val = i+1;
		scanf("%d", &ch);
		while(ch!= 99)
		{
			
			temp = (node*)malloc(sizeof(node));
			temp->val = ch;
			temp->next = NULL;
			scanf("%d", &ch);
		}
		
		if(i==n-1)
		{
			master->next = NULL;
		}
		else
		{
			master->next = (node*)malloc(sizeof(node));
			master = master->next;
		}

	}


	return 0;
}