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

void null(int arr[])
{
	int i =0;
	for(i;i<size;i++)
	{
		arr[i] = '\0';
	}
}

int len(int arr[])
{
	int i =0;
	while(arr[i++]!='\0');
	return i-1;
}

int search(char arr[], int strt, int end, char value)
{
  int i;
  for(i = strt; i <= end; i++)
  {
    if(arr[i] == value)
      return i;
  }
}

void print(tree * head)
{
	if(head==NULL)
		return;
	print(head->left);
	print(head->right);
	
	
	printf("%d ", head->data);
	
	
}



tree * inpre(int in[], int pre[], int instart, int inend)
{
	static int ind=0;
	if(instart > inend)
		return NULL;
	
	tree * root = newnode(pre[ind++]);

	if(instart == inend)
		return root;

	int ind1= search(in, instart,inend,root->data);

	root->left = inpre(in,pre,instart,ind1-1);
	root->right = inpre(in,pre,ind+1,inend);
	return root; 

}

int main(int argc, char const *argv[])
{
	int in[size],other[size],i=0;
	printf("Enter the inorder traversal of the tree. Press 999 to stop.\n");
	int ch=0;
	null(in);
	while(1)
	{
		scanf("%d", &ch);
		if(ch==999)
			break;
		in[i]= ch;
		
		i++;
	}
	
	printf("Enter preorder traversal\n");
	null(other);
	i =0;
	while(1)
	{
		scanf("%d", &ch);
		if(ch==999)
			break;
		other[i]= ch;
		i++;
	}
	

	if(len(in)!=len(other))
	{
		printf("Unequal lengths entered. \n");
		exit(0);
	}
	else
	{
		for(i=0;i<len(in);i++)
			printf("%d ", in[i]);
		printf("\n");
		for(i=0;i<len(other);i++)
			printf("%d ", other[i]);
		printf("\n");
		printf("The postorder traversal of the tree is\n");
		tree * final = inpre(in,other,0,len(in));
		print(final);
		printf("\n");

	}

	


	return 0;
}