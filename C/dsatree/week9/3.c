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

int search(int arr[],int begin, int end,int val)
{
	int i =begin,flag =1;
	for(i;i<=end;i++)
	{
		if(arr[i]==val)
		{
			flag = 0;
			break;
		}
	}
	if(!flag)
		return i;
	else
		return;
}

void print(tree * head)
{
	if(head==NULL)
		return;
	if(head->left!= NULL)
		print(head->left);
	if(head->right!= NULL)
		print(head->right);
	printf("%d ", head->data);
	
	
}



tree * inpre(int in[], int pre[], int instart, int inend)
{
	static int ind;
	if(li>hi || lp >hp)
		return NULL;
	
	tree * root = newnode(pre[in++]);
	if(instart > inend)
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
	printf("Next, preorder(0) or postorder(1) traversal\n");
	scanf("%d", &ch);
	if(ch==1)
	{
		printf("Enter postorder traversal\n");
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
			tree * final = inpost(in,0,len(in)-1, other,0,len(other)-1);
			//print(final);

		}

	}


	return 0;
}