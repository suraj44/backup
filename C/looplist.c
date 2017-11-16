#include <stdio.h>
#include <stdlib.h>
struct N
{
	int data;
	struct N * next;
};



typedef struct N node;

void display(node *);
void push(node*,int,int);
void pop(node*,int);

int main()
{
	node * head = NULL;
	head = (node *)malloc(sizeof(node));
	head ->data = 0;
	head->next = head;
	int ch =0,el,pos,i;
	while(1){
		printf("Enter:\n1.Push\n2.Pop\n0.exit\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to be pushed\n");
				scanf("%d", &el);
				printf("Enter the position\n");
				scanf("%d", &pos);
				push(head,el, pos);
				break;
			case 2:
				printf("Enter the position to pop element\n");
				scanf("%d", &pos);
				pop(head,pos);
				//printf("The element popped is %d", pop(head,pos));
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid input\n");
				break;
		}
		printf("flag\n");
		display(head);
		
	}
	return 0;

}

void display(node * head)
{
	printf("\n");
	printf("\n");
	node * current= head;
	int count = 0;
	while(current->next!= head)
	{

		current = current->next;
		if(current->next==head)
		{
			printf("%d", current->data);
			count++;
		}
		else
			printf("%d->", current->data);
		
	}
	printf("\n");
	printf("\n");
}

void push(node * head,int a, int n)
{
	int i = 0;
	node * current = head;
	node * tmp = NULL;
	for(i=0 ; i<n-1;i++)
	{
		if(current->next==head)
		{
			break;
		}
		current = current->next;
	}
	tmp= current->next;
	current->next = (node*)malloc(sizeof(node));
	current->next->data = a;
	//printf("%d \n", tmp );
	current->next->next= tmp;
	// node * current = head;
	// node * tmp;
	// while(current->next!=NULL&& pos > 0)
	// {
	// 	current = current->next;
	// 	if(pos==1)
	// 	{
	// 		tmp->next = current->next;
	// 	}
	// 	pos--;
	// }
	// tmp = current->next;
	// current->next = (node*)malloc(sizeof(node));
	// current->next->data = a;
	// current->next->next = tmp;
}

void pop(node * head,int pos)
{
	node * current = head;
	node * tmp = NULL;
	while(current->next != head && pos > 1)
	{
		current = current->next;
		pos--;

	}
	tmp = current->next;
	current->next = tmp->next;
}