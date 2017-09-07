#include <stdio.h>
#include <stdlib.h>
struct N
{
	int data;
	struct N * next;
};

typedef struct N node;

void print(node*);
void push(node*,int,int);
void pop(node*,int);
void sort(node*);
int top= 0

main()
{
	int ch =1;

	node * head= NULL;

	int el,pos;
	head = 0;
	head = (node*)malloc(sizeof(node));
	head->data = NULL;
	head->next= NULL;
	while(ch !=0)
	{
		printf("Enter \n1.To insert a node\n2. To delete a node \n3. To sort \n0. Exit\n");
		scanf("%d", &ch);



		switch(ch)
		{
			case 1:
				printf("Enter element and position\n");
				scanf("%d %d", &el,&pos);
				push(head, el, pos);
				print(head);
				break;
			case 2:
				printf("Enter the position to be deleted\n");
				scanf("%d", &pos);
				//printf("SCENE\n");
				pop(head,pos);
				print(head);
				break;
			case 3:
				sort(head);
				print(head);
			case 0:
				exit(0);
		}



	}
}

// void print(node * head)
// {

// 	node * current = head->next;

// 	do
// 	{

// 		printf("%d ", current->data);

// 		current = current->next;

// 	}
// 	while(current->next != NULL);
// 	printf("FLAGGG\n");	
// 	printf("\n");
// }

void print(node * head)
{
	printf("\n");
	printf("\n");
	node * current = head->next;
	while(current != NULL)
	{
		printf("%d ", current->data );
		current = current->next;

	}
	printf("\n");
}

void push(node * head,int dat, int n)
{
	node * current = head;
	int i;
	node * tmp;
		

	for(i= 0 ; i<n-1;i++)
	{
		
		if(current->next == NULL)
			break;
		current = current->next;
	}
	tmp= current->next;
	current->next = (node*)malloc(sizeof(node));
	current->next->data = dat;
	//printf("%d \n", tmp );
	current->next->next= tmp;
}



void pop(node * head, int n)
{
	int i = 0;
	node * current = head;
	node * tmp = NULL;
	for(i=0 ; i<n-1;i++)
	{
		if(current->next==NULL)
		{
			break;
		}
		current = current->next;
	}
	tmp = current->next;
	current->next = tmp->next;

}