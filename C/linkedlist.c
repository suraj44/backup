#include <stdio.h>
#include <stdlib.h>
struct N
{
	int data;
	struct N * next;
};

typedef struct N node;

main()
{
	node * head = NULL;
	head = (N*)malloc(sizeof(N));
	head->val = 1;
	head->next = (N*)malloc(sizeof(N));
	head->next->val = 2;
	head->next->next = NULL;


}

void print(N * head)
{
	N * current =head;
	while(current!=NULL)
	{
		printf("%d\n", current->val);
		current = current->next;
	}
}