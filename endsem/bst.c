#include <stdio.h>
#include <stdlib.h>
struct T
{
	int data;
	struct T * left;
	struct T* right;
};

typedef struct T tree;

tree * newnode(int el)
{
	tree * new = (tree*)malloc(sizeof(tree));
	new->data = el;
	new->left = NULL;
	new->right = NULL;
	return new;
}

tree * insert(tree * root, int el)
{
	if(root==NULL)
	{
		root = newnode(el);
	}
	else
	{
		if(el>root->data)
		{
			if(root->right==NULL)
			{
				root->right= newnode(el);
			}
			else
			{
				insert(root->right,el);
			}
		}
		else if(el<= root->data)
		{
			if(root->left==NULL)
			{
				root->left= newnode(el);
			}
			else
			{
				insert(root->left,el);
			}
		}
	}
	return root;
}

int findmin(tree *node)
{
	while(node->left!= NULL)
	{
		node = node->left;
	}
	return node->data;
}
tree * delete(tree * root, int el)
{
	if(root!=NULL)
	{
		if(el == root->data)
		{
			if(root->left ==NULL)
			{
				tree * temp = root->right;
				free(root);
				return temp;
			}
			else if(root->right ==NULL)
			{
				tree * temp = root->left;
				free(root);
				return temp;
			}
			else if (root->left!= NULL && root->right != NULL)
			{
				root->data = findmin(root->right);
				root->right = delete(root->right, root->data);
			}
			else
			{

			}
		}
		if(el>root->data)
		{
			if(root->right!= NULL)
				root->right = delete(root->right, el);
		}
		if(el<= root->data)
		{
			if(root->left!= NULL)
				root->left = delete(root->left, el);
		}
		return root;
	}
}

void print(tree *root)
{
	if(root==NULL)
		return;
	printf("%d ", root->data);
	print(root->left);
	print(root->right);
}

int main(int argc, char const *argv[])
{
	tree * root = NULL;
	int i,j, ch ,el;
	while(1)
	{
		printf("Enter your choice:\n1. Insert\n2. Delete\n3. Display\n 0.Exit");
		scanf("%d", &ch);
		if(ch==1)
		{
			printf("Enter an element to be inserted\n");
			scanf("%d", &el);
			root = insert(root,el);
		}
		else if(ch==2)
		{
			printf("Enter an element to be deleted\n");
			scanf("%d", &el);
			root = delete(root,el);
		}
		else if(ch==3)
		{
			printf("The tree is ");
			print(root);
			printf("\n");
		}
		else if(ch==0)
		{
			exit(0);
		}
	}
	return 0;
}