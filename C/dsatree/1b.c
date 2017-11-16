#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 20

int tree[size];

int insert(int tree[], int val, int ind)
{
	int ch;
	if(tree[0]==NULL)
	{
		tree[0] = val;
	}
	else
	{
		printf("Left(0), right(1) of %d or replace(2) it?\n", tree[ind]);
		scanf("%d", &ch);

		if(ch==0)
		{
			if(tree[(int)2*ind +1]==NULL)
			{
				tree[(int)(2*ind+1)] = val;
			}
			else
			{
				insert(tree, val, (int)(2*ind+1));
			}
			

		}
		else if(ch==1)
		{
			if(tree[(int) 2*ind+2 ]==NULL)
			{
				tree[(int)(2*ind+2)] = val;
			}
			else
			{
				insert(tree, val, (int) (2*ind+2));
			}
			
		}
		else if(ch==2)
		{
			tree[ind]= val;
		}
		else
			printf("Invalid input\n");
	}
		

}
// only prints root and its immediate children
void print(int tree[],int ind)
{
	if(tree[ind]==NULL)
		return;
	printf("%d ", tree[ind]);
	if(tree[(int) 2*ind +1]!= NULL)
		print(tree,(int) (2*ind+1));
	if(tree[(int) 2*ind +2]!= NULL)
		print(tree, (int) (2*ind+2));
	
}

int search(int tree[], int val,int ind)
{
	if(tree[ind]!= NULL)
	{
		if(tree[ind]==val)
			return 1;
		else
			return search(tree,val,(int) (2*ind+1)) || search(tree,val,(int) (2*ind+2));
	}
	
	
}


int delete(int tree[], int val, int ind)
{
	if(tree[ind]!= NULL)
	{
		if(tree[ind]==val)
			tree[ind] = NULL;
		delete(tree,val,(int) (2*ind+1)) ;
		delete(tree,val,(int) (2*ind+2));
	}
	else
		return;

}
int main(int argc, char const *argv[])
{
	int i;
	for(i=0;i<size;i++)
		tree[i] = NULL;
	//tree * head;
	//head->data = NULL;
	int c,el;
	while(1)
	{
		printf("Enter your choice\n1. Add element\n2. Display the tree\n3. Search\n0. Exit\n ");
		scanf("%d", &c);
		if(c==1)
		{
			printf("Enter the element to be added\n");
			scanf("%d", &el);
			insert(tree, el, 0);
			//printf("%d", head->data);
		}
		else if(c==2)
		{
			printf("The tree is ");
			print(tree,0);
			printf("\n");
		}
		else if(c==3)
		{
			printf("Enter the element to be searched for\n");
			scanf("%d", &el);
			if(search(tree, el,0))
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
			delete(tree, el ,0);
			//print(head);
			printf("\n");	
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
		for(i=0;i<size;i++)
			printf("%d ", tree[i]);
		printf("\n");


	}


	return 0;
}