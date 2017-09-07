#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char*);
main()
{
	int i,j,states,lent,tmp;

	printf("Enter the number of states\n");
	scanf("%d",&states);
	int table[states][2];
	char str[50];
	int nf, f[10],flag=0;
	int ch=1;
	for(i=0;i<states;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter which state to go from %d if it encounters %d\n",i,j);
			scanf("%d", &table[i][j]);
			if(table[i][j]>=states)
			{
				printf("Invalid input\n");
				exit(0);
			}
		}
	}
	for(i=0;i<states;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
	printf("Enter the number of final states\n");
	scanf("%d", &nf);
	printf("Enter the final states:\n");
	for(i=0;i<nf;i++)
	{
		scanf("%d", &f[i]);
	}
	while(ch!=0)
	{
		printf("Enter a string containing 0s and 1s\n"); //Make the alphabet user input
		scanf("%s", str);
		lent = len(str);
		tmp =0;
		for(i=0;i<lent;i++)
		{
			tmp = table[tmp][(int)str[i]-48];
			printf("char: tmp: %d %d\n", (int)str[i]-48,tmp);
		}
		printf("\n");

		
		for(i=0;i<nf;i++)
		{
			if(f[i]==tmp)
			{
				printf("final tmp %d %d\n", f[i],tmp);
				flag =1;
				break;
			}

		}
		if(flag)
			printf("the string is accepted\n");
		else
			printf("the string is not accepted\n");
		printf("Enter 0 to exit, any other digit to try again\n");
		scanf("%d", &ch);
	}

}

int len(char* a)
{
	int i=0;
	while(a[i] != '\0')
		i++;
	return i;
}
