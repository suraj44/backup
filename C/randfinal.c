/*
SURAJ SINGH
16CO146
The following programs converts an inputted number in base x to its equivalent in base y
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int othertodec(char*,int);
void dectoother(int,int);
int strtoint(char*);
char* inttostr(int);
char hexa(char);
main()
{
	int n,i,invar, outvar, inbase, outbase, tmp, flag=1,base;
	char in[10];
	char t[10];
	
	printf("Enter the initial and final base systems ( x and y)\n");
	scanf("%d %d", &inbase, &outbase);

	n = (rand() % inbase )* (rand() % inbase );

	printf("(%s)%d is equal to ", n, inbase);
	dectoother(othertodec(inttostr(n),inbase),outbase);
	
	//inbase =10;
	n = (rand() % inbase )* (rand() % inbase );

	//Sprintf("%s", inttostr(n));
	printf("\n");

}

int len(char* a)
{
	int i=0;
	while(a[i] != '\0')
		i++;
	return i;
}
void rev(char* a)
{
	int l = len(a)-1;
	int i =0;
	int tmp;
	while(i<l)
	{
		tmp = a[i];
		a[i] = a[l];
		a[l] = tmp;
		i++;
		l--;
	}
}


int strtoint(char* a)
{
	int i =0,p=0,ans=0,tmp=0;
	int l = len(a);
	rev(a);
	for(i=0; i<l;i++)
	{
		if (hexa(a[i])-48<6)
			tmp = hexa(a[i]) - 48 +10;
		else
			tmp = a[i] - 48;
		ans += tmp * pow(10,p);
		p++;

	}
	return ans;
}

char * inttostr(int n)
{
   int i=0,c, rem, tmp;
   char a[10];

   while(n>0)
   {
   	  printf("LOLOL\n");
   	//printf("");
      tmp = n % 10;
      printf("%d\n", tmp);
      tmp+=48;
      a[i]  = tmp;
      i++;
      n/=10;

   }
   a[i] = '\0';
   rev(a);
   return a;

}
char hexa(char c)
{
	if ( c=='A' || c=='a')
		return '0';
	else if ( c=='B' || c=='b')
		return '1';
	else if ( c=='C' || c=='c')
		return '2';
	else if ( c=='D' || c=='d')
		return '3';
	else if ( c=='E' || c=='e')
		return '4';
	else if ( c=='F' || c=='f')
		return '5';
	else return '6';
}

int othertodec(char * a, int base)
{
	
	int l = len(a);
	
	rev(a);

	
	//a[l] = '\0';

	int ans=0,tmp =0;
	int i =0;
	int p = 0;
	
	while(a[i] != '\0')
	{
		if (hexa(a[i])-48<6)
			tmp = hexa(a[i]) - 48 +10;
		else
			tmp = a[i] - 48;
		//printf("%c\n", tmp);
		if (tmp>=base)
		{
			printf("invalid input\n");
			exit(0);
		}

		ans+= tmp * pow(base,p);
		p++;
		i++;
	}
	return ans;

}

void dectoother(int num, int base)
{
	int i =0,rem,tmp,p =0 ;
	char ans[15];
	while(num>0)
	{

		tmp = num %base;
		if(tmp > 9)
			tmp+=39;
		tmp +=48;

		ans[i] = tmp;
		i++;

		num/=base;

	}
	ans[i] = '\0';
	rev(ans);
	printf("(%s)%d\n",ans,base );

}