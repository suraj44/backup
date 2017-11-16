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



tree * search(tree * head, int val)
{
	if(head!= NULL)
	{
		if(head->data == val)
			return head;
		else
			return search(head->left,val) || search(head->right,val);
	}

	
	
}




int delete(tree * head, int val)
{
	if(head!=NULL)
	{
		if(search(head,val))
		{
			if(head->data==val)
			{
				head->data = NULL;
				head->left = NULL;
				head->right = NULL;
				head=NULL;
				return;
			}
			if(head->right != NULL)
			{
				if(head->right->data==val)
					head->right=NULL;
			}
			if(head->left != NULL)
			{
				if(head->left->data==val)
					head->left=NULL;
			}
			if(head->left != NULL)
				delete(head->left, val);
			if(head->right != NULL)
				delete(head->right,val);
		}
	}

}

int main(int argc, char const *argv[])
{
	tree * head;
	head->data = NULL;
	int c,el;
	while(1)
	{
		printf("Enter your choice\n1. Add element\n2. Display the tree\n3. Search\n4. Delete a node\n0. Exit\n ");
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
			printf("Enter the element to be searched for\n");
			scanf("%d", &el);
			if(search(head, el))
			{
				printf("%d is present in the tree\n", el);
			}
			else
				printf("%d is NOT in the tree\n",el);	
			//printf("%d", head->data);
		}
		else if(c==4)
		{
			printf("Enter the element to be deleted\n");
			scanf("%d", &el);
			 delete(head, el);
			// //print(head);
			// printf("\n");	
			// //printf("%d", head->data);
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