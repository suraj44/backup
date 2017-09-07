#include <stdio.h>
#include <math.h>
int len(char*);
void  rev(char*);
char hexa(char);
main()
{
	int r,n=0,ans,tmp,rem=0,flag = 1,i=0,dig;
	char  N[20];
	char t[20],t2[20];
	printf("Enter r: ");
	scanf("%d", &r);
	printf("Enter the number: ");
	scanf("%s", &N);
	//tmp = N;

	//rev(N);
	//printf("reversed %s\n", N);
	N[len(N)]= '\0';
	for(i=0;i<(len(N));i++)
	{
		//printf("%d\n", i);
		if( hexa(N[i])-48)
		{
			tmp = (int)hexa(N[i])- '0' +10;

		}
		else	
			tmp = (int)N[i] - '0';
		//printf("TMP %d\n", tmp);
		if(tmp>r-1)
		{
			flag =0;
			printf("invalid input\n");
			break;
		}
		dig = (r-1) - tmp;
		if(i == len(N)-1)
			dig++;
		dig+=48;
		t[i] = dig;
		printf("%c\n", t[i]);

	}
	t[i] = '\0';
	if(flag)
	{
	printf("The r's complement of the number is %s\n", t);
	t[len(N)-1]--;
	printf("The (r-1)'s complement of the number is %s\n", t);
	}
	
}

char hexa(char a)
{
	if (a=='A' || a=='a')
		return '0';
	else if (a=='B' || a=='b')
		return '1';
	else if (a=='c' || a=='C')
		return '2';
	else if (a=='D' || a=='d')
		return '3';
	else if (a=='E' || a=='e')
		return '4';
	else if(a=='F'|| a=='f')
		return '5';
	else 
		return '0';

}

int len(char* a)
{
	int i = 0;
	while(a[i] != '\0')
	{
		i++;
	}
	return i;
}

void rev(char* b)
{
	int i=0;
	int n = len(b)-1;
	//printf("LALALALA %d\n", len(b));
	char tmp;
	while(i<n)
	{
		tmp = b[i];
		b[i] = b[n];
		b[n] = tmp;
		i++;
		n--;
	}
	
}