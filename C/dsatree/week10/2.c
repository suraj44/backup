#include <stdio.h>
#include <stdlib.h>
#define size 20
struct T
{
	int data;
	struct T * left;
	struct T * right;
};

typedef struct T tree;


tree * newnode(int val)
{
	tree * new = (tree*)malloc(sizeof(tree));
	new->data = val;
	new->right = NULL;
	new->left = NULL;
	return new;
}

tree * insert(tree * head, int val)
{
	int ch;
	if(head->data==NULL)
	{
		// printf("check\n");
		head->data = val;
		head->right = NULL;
		head->left = NULL;
		printf("%d\n", head->data);
		return;
	}
	else
	{
		

		if(val<= head->data)
		{
			if(head->left!= NULL)
				insert(head->left, val);
			else
				head->left = newnode(val);
		}
		else if(val>head->data)
		{
			if(head->right != NULL)
				insert(head->right,val);
			else
				head->right = newnode(val);
		}
	}

}

void inprint(tree * head)
{
	if(head==NULL)
		return;
	
	if(head->left!= NULL)
		inprint(head->left);
	printf("%d ", head->data);
	if(head->right!= NULL)
		inprint(head->right);
	
}

int main()
{
	tree * head = (tree*)malloc(sizeof(tree));
	head->data= NULL;
	int c,el, i,path[size];
	
	int  level;
	printf("Enter a set of numbers to be sorted using BST. Enter 99 to stop input\n");
	for(i=0;i<size;i++)
	{
		scanf("%d", &c);
		if(c!= 99)
			path[i] = c;
		else

			break;
	}
	path[i] = '\0';
	for(i=0;path[i]!='\0';i++)
	{
		insert(head, path[i]);
	}
	printf("The sorted numbers are\n");
	inprint(head);
	printf("\n");
}