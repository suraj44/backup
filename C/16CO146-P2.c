#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int othertodec(char*,int);
char* dectoother(int,int);

main()
{
	int i,invar, outvar, inbase, outbase, tmp, flag=1,base;
	char in[10];
	int ran = rand() %1000;

	printf("Enter 'x' base system\n");
	scanf("%d", &inbase);
	printf("Enter 'y' base system\n");
	scanf("%d", &outbase);
	printf("%d\n", ran);
	printf("The randomly generated number is (%s)\n", dectoother(ran, inbase));
	printf("Its equivalent in base %d is %s\n",outbase, dectoother(ran, outbase) );

	/*
	printf("(%s)%d is equal to ", in, inbase);
	dectoother(othertodec(in,inbase),outbase);
	*/
	
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

char* dectoother(int num, int base)
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
	return ans;

}