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
	printf("%d ", head->data);
	if(head->left!= NULL)
		print(head->left);
	if(head->right!= NULL)
		print(head->right);
	
}

int height(tree * head)
{
	if(head==NULL)
		return 0;
	else
	{

	int rval = height(head->right);
	int lval = height(head->left);
	if(lval>rval)
		return lval +1;
	else
		return rval +1;

	}	
	
	
}


int peRFect(tree * head, int h, int level)
{
	if(head==NULL)
		return 1;
	if(head->right==NULL && head->left == NULL)
		return (h==level +1);
	if(head->right==NULL || head->left == NULL)
		return 0;
	return peRFect(head->right,h, level+1) && peRFect(head->left, h, level+1);
}


int noofnodes(tree * head)
{
	if(head==NULL)
		return 0;
	else
		return 1 + noofnodes(head->left) + noofnodes(head->right);
}

int complete(tree * head, int ind, int nodes)
{
	if (head==NULL)
		return 1;
	if (ind>=nodes)
		return 0;
	return complete(head->left, 2*ind+1, nodes) && complete(head->right, 2*ind+2, nodes);

}


int full(tree * head)
{
	if(head==NULL)
		return 1;
	if(head->right == NULL && head ->left == NULL)
		return 1;
	if (head->right != NULL && head->left != NULL)
		return 1;
	if(head->right == NULL || head ->left == NULL)
		return 0;
	return full(head->right) && full(head->left);
}

int main(int argc, char const *argv[])
{
	tree * head;
	head->data = NULL;
	int c,el;
	while(1)
	{
		printf("Enter your choice\n1. Add element\n2. Display the tree\n3. Find if the tree is perfect\n4. Find if the tree is complete\n5. Find if the tree is full\n0. Exit\n ");
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
			if(peRFect(head,height(head),0))
				printf("The tree is perfect\n");
			else
				printf("The tree is NOT perfect\n");
		}
		else if(c==4)
		{
			if(complete(head,0,noofnodes(head)))
				printf("The tree is complete\n");
			else
				printf("The tree is NOT complete\n");
		}
		else if(c==5)
		{
			if(full(head))
				printf("The tree is full\n");
			else
				printf("The tree is NOT full\n");
		}

		else if(c==0)
		{
			exit(0);
		}
		else
		{
			printf("Invalid option\n");
		}


	}
	return 0;
}