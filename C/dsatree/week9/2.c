#include <stdio.h>
#include <stdlib.h>
#define size 20

struct T
{
	char data;
	struct T * right;
	struct T * left;
};

typedef struct T tree;

tree * stack[size]; //for operands
tree * stack1[size]; // for operators
int top = -1;
int top1 = -1;



void push(tree * a)
{
	top++;
	stack[top]= a;
	
}

void push1(tree * a)
{
	top1++;
	stack1[top1]= a;
	
}


tree * pop()
{

	tree * tmp;
	tmp = stack[top];
	top--;
	return tmp;
}

tree * pop1()
{

	tree * tmp;
	tmp = stack1[top1];
	top1--;
	return tmp;
}

int precedence(char s)
{
	if(s=='^')
		return 3;
	else if(s=='/' || s=='*')
		return 2;
	else if(s=='+'|| s=='-')
		return 1;
	else
		return 0;
}

int isop(char s)
{
	if (s=='^'||s=='+'||s=='-'||s=='/'||s=='*')
		return 1;
	else
		return 0;

}

tree * newnode(char val)
{
	tree * new = (tree*)malloc(sizeof(tree));
	new->data = val;
	new->left = NULL;
	new->right= NULL;
	return new;
}



tree * exptree(char in[])
{
	int i=0;
	char tmp = in[i];
	tree *  new,*op, *t1, *t2, *x;
	while(in[i]!='\0')
	{
		if(isalpha(in[i]) || isdigit(in[i]))
		{
			//printf("%c\n", in[i]);

			new = newnode(in[i]);
			push(new);
		}
		else if(isop(in[i]))
		{
			if(top1>=0 && top>0)
			{	
				x = pop1();

				if(precedence(in[i])<=precedence(x->data))
				{
					while(isop(x->data)&&precedence(in[i])<=precedence(x->data))
					{
						printf("%c\n", x->data);
						t1 = pop();
						t2 = pop();
						x->right = t1;
						x->left = t2;
						push(x);
						if(top1>-1)
							x = pop1();
						else
							break;
						printf("final loop\n");
						
					}
					if(top1>-1)
						push1(x);

					new = newnode(in[i]);
					push1(new);
				}
				else
				{
					push1(x);
					push1(newnode(in[i]));
					
				}


			// printf("%c\n", in[i]);
			// new = newnode(in[i]);
			// push1(new);
			}
			else
			{
				new = newnode(in[i]);
				push1(newnode(in[i]));
			}
		}
		i++;
	}
	printf("operands: %d operators: %d\n", top, top1);
	for(i=top;i>=0;i--)
	{
		new = stack[i];
		printf("%c ", new->data);
	}
	printf("\n");
	for(i=top1;i>=0;i--)
	{
		new = stack[i];
		printf("%c ", new->data);
	}
	//Building the tree
	while(top!=0 && top1>-1)
	{

		// new = stack[0];
		// printf("%c\n", new->data);
		if(top>=1)
		{
			
			op = pop1();
			t1 = pop();
			t2 = pop();
			op->right = t1;
			op->left = t2;
			push(op);
		}
		else
		{
			printf("invalid expression\n");
			exit(0);
		}
		if(top1==-1)
			break;
		
	}
	return stack[0];
}


void preprint(tree * head)
{
	if(head==NULL)
		return;
	printf("%c ", head->data);
	if(head->left!= NULL)
		preprint(head->left);
	if(head->right!= NULL)
		preprint(head->right);
	
}

void inprint(tree * head)
{
	if(head==NULL)
		return;
	
	if(head->left!= NULL)
		inprint(head->left);
	printf("%c ", head->data);
	if(head->right!= NULL)
		inprint(head->right);
	
}

void postprint(tree * head)
{
	if(head==NULL)
		return;
	
	if(head->left!= NULL)
		postprint(head->left);
	if(head->right!= NULL)
		postprint(head->right);
	printf("%c ", head->data);
	
}
int main(int argc, char const *argv[])
{
	char in[20];
	int ch;
	printf("Enter an infix expression\n");
	scanf("%s" , in);
	int j=0;
	
	tree * head=exptree(in);
	while(1)
	{
		printf("Enter:\n1. Inorder traversal\n2. Preorder traversal\n3. Postorder traversal\n0. Exit\n ");
		scanf("%d", &ch);
		if(ch==1)
		{
			inprint(head);
			printf("\n");
		}
		else if(ch==2)
		{
			preprint(head);
			printf("\n");

		}
		else if(ch==3)
		{
			postprint(head);
			printf("\n");
		}
		else if(ch==0)
		{
			break;
		}
		else
		{
			printf("Invalid input\n");
		}

	}

	return 0;
}
