#include <stdio.h>
#include <stdlib.h>

struct N
{
	int data;
	struct N  * p;	
};
typedef struct N node;

node* XOR(node* a, node* b)
{
	return (node *) ((unsigned int) (a) ^ (b)); 
}

void insert(node ** head,int data)
{
		node * current = (node*)malloc(sizeof(node));
		current->data = data;
		current->p = XOR(*head, NULL);
		if(head!= NULL)
		{
			node* next = XOR((*head)->p,NULL);
			(*head)->p = XOR(current, next);
		}
		*head = current;
}

void print(node*head)
{
	node *current = head;	
	node * prev = NULL;
	node * next;
	while(current != NULL)
	{
		printf("%d ", current->data);
		next = XOR(prev, current->p);
		prev = current;
		current = next;
	}
}


main()
{
	node * head = NULL;
}