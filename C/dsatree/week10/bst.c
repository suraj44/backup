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

void print(tree * head)
{
	if(head==NULL || head->data == NULL)
		return;
	printf("%d ", head->data);
	if(head->left!= NULL)
		print(head->left);
	if(head->right!= NULL)
		print(head->right);
	
}




int search(tree * head, int val, int level,int arr[], int ind)
{ 

	if(head!= NULL)
	{
		arr[ind++] = head->data;
		(level)+=1;

		if(head->data == val)
				return level;
		else if(val>head->data)
			return search(head->right, val, level,arr,ind);
		else if(val<=head->data)
			return search(head->left,val,level,arr,ind);
	}
	else
		return;
}


int max(tree*head)
{
	if(head!=NULL)
	{
		if(head->right==NULL)
			return head->data;
	max(head->right);
	}
}

int min(tree*head)
{
	if(head!=NULL)
	{
		if(head->left==NULL)
			return head->data;
	min(head->left);
	}
}


void delete(tree * head, int val)
{
	if(head!=NULL)
	{
		if(head->right)
		{
			if(head->right->data==val)
			{
				if(head->right->right==NULL && head->right->left==NULL)
				{
					head->right = NULL;
					return;
				}
			}
		}
		if(head->left)
		{
			if(head->left->data==val)
			{
				if(head->left->right==NULL && head->left->left==NULL)
				{
					head->left= NULL;
					return;
				}
			}
		}
		if(head->right && !head->left)
		{
			if(head->data == val)
			{
				head->data  = head->right->data;
				head->right = NULL;
			}
		}

		if(!head->right && head->left)
		{
			if(head->data == val)
			{
				head->data  = head->left->data;
				head->left = NULL;
			}
		}
		if(head->right && head->left)
		{
			if(head->data==val)
			{
				head->data = min(head->right);
				delete(head->right, head->data);
			}
		}
		if(!head->right && !head->left)
		{
			if(head->data == val)
			{
				head->data = NULL;
				head = NULL;
			}
		}
		if(head!= NULL)
		{
			if(val>head->data && head->right != NULL)
				delete(head->right, val);
			if(val<=head->data  && head->left != NULL)
				delete(head->left,val);
		}

	}
}


// tree * srch(tree * head, int val)
// {
// 	if(head!= NULL)
// 	{
// 		if(head->data == val)
// 				return head;
// 		else
// 			return search(head->left,val) || search(head->right,val);
// 	}

	
	
// }


int main()
{
	tree * head = (tree*)malloc(sizeof(tree));
	head->data= NULL;
	int c,el, i,path[size];
	
	int  level;
	
	while(1)
	{
		printf("Enter your choice\n1. Add element\n2. Display the tree\n3. Search\n4. Delete a node\n5. Max element\n6. Mininimum element\n0. Exit\n ");
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
			for(i=0;i<size;i++)
				path[i]= '\0';

			printf("Enter the element to be searched for\n");
			scanf("%d", &el);
			if(search(head, el,0,path,0))
			{
				level =search(head,el,0,path,0);
				printf("%d is present in the tree\n", el);
				printf("The path is:\n");

				for(i=0;i<level;i++)
					printf("%d ", path[i]);
				printf("\n");
				printf("The level of the node is %d\n", level);
			}
			else
				printf("%d is NOT in the tree\n",el);	
		
		}
		else if(c==4)
		{
			printf("Enter the element to be deleted\n");
			scanf("%d", &el);
			if(search(head, el,0,path,0))
			{
				delete(head, el);
			}
			else
				printf("%d is NOT in the tree\n",el);	
		
		}
		else if(c==5)
		{
			printf("The maximum element of the BST is %d", max(head));
			printf("\n");
		}
		else if(c==6)
		{
			printf("The maximum element of the BST is %d", min(head));
			printf("\n");
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