#include <stdio.h>
#include <stdlib.h>
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
	}
	else
	{
		printf("Left(0), right(1) of %d or replace(2) it?\n", head->data);
		scanf("%d", &ch);

		if(ch==0)
		{
			if(head->left==NULL)
			{
				head->left = newnode(val);
			}
			else
			{
				insert(head->left, val);
			}
			

		}
		else if(ch==1)
		{
			if(head->right==NULL)
			{
				head->right = newnode(val);
			}
			else
			{
				insert(head->right, val);
			}
			
		}
		else if(ch==2)
		{
			head->data= val;
		}
		else
			printf("Invalid input\n");
	}

}

void print(tree * head)
{
	if(head==NULL)
		return;
	if(head->data != NULL)
		printf("%d ", head->data);
	if(head->left!= NULL)
		print(head->left);
	if(head->right!= NULL)
		print(head->right);
	
}



int isbst(tree * head)
{
	if(head!= NULL)
	{

		if(head->left)
		{
			if(head->left->data<=head->data)
			{
				if(head->right)
				{
					if(head->right->data>head->data)
					{
						return 1;
					}
				}
			}
		}
		if (head->right)
		{
			if(head->right->data >head->data)
			{
				if(head->left)
				{
					if(head->left->data <= head->data)
					{
						return 1;
					}
				}
			}
		}
		return isbst(head->left) && isbst(head->right);
	
	}
}
int main(int argc, char const *argv[])
{
	tree * head;
	head->data = NULL;
	int c,el;
	while(1)
	{
		printf("Enter your choice\n1. Add element\n2. Display the tree\n3. Check if it is BST\n0. Exit\n ");
		scanf("%d", &c);
		if(c==1)
		{
			printf("Enter the element to be added\n");
			scanf("%d", &el);
			insert(head, el);
			//printf("%d", head->data);
		}
		else if(c==2)
		{
			printf("The tree is ");
			print(head);
			printf("\n");
		}
		else if(c==3)
		{
			if(isbst(head))
			{
				printf("The tree is a BST\n");
			}
			else
				printf("The tree is NOT a BST\n");	
			//printf("%d", head->data);
		}

		else if(c==0)
		{
			exit(0);
		}
		else
		{
			printf("Invalid option\n");
		}
		printf("\n");


	}
	return 0;
}