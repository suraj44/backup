/*
SURAJ SINGH
16CO146
PRoving the self complementing property of a weighted number system
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int len(char*);
void rev(char*);
char* dectoother(int);
char* nine(int);
main()
{
	int in, i, j, tmp,s;
	printf("\n");
	printf("Enter a decimal number\n");
	scanf("%d", &in);
	printf("The BCD equivalent of %d is ",in);
	printf("%s\n", dectoother(in));

	printf("The nine's complement of the decimal number inputed is %s and its equivalent in BCD is ", nine(in));
	printf("%s\n",dectoother(strtoint(nine(in))) ); 
	printf("Therefore, BCD is not self  comlementing.\n");
	printf("\n");
	printf("\n");
	printf("The Excess-3 representation of %d is ", in );
	printf("%s\n", dectoother(in+3));
	printf("Its nine's complement is %s and its Excess-3 equivalent is ", nine(in));
	printf("%s\n", dectoother(strtoint(nine(in))+3));
	printf("Therefore, the self complementing property for Excess-3 (weighted code) is proved.\n");
	//printf("%d\n", strtoint("7"));	
	//printf("%s\n",dectoother(in+3));
	//printf("%s\n", nine(in));
	//printf("%s\n",dectoother(strtoint(nine(in))+3) );
	printf("\n");
	//nine(in);


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

char* nine(int num)
{
	int i=0, rem, tmp;
	char lol[15];
	
	while(num>0)
	{
		
		tmp = num%10;
		rem = 9-tmp +48;
		lol[i] = rem;
		i++;
		num/=10;
		
	}

	lol[i] = '\0';
	
	

	rev(lol); 
	return lol;
	
}

int strtoint(char* a)
{
	int i =0,p=0,ans=0,tmp=0;
	int l = len(a);
	rev(a);
	for(i=0; i<l;i++)
	{
		tmp = a[i] - 48 ;
		ans += tmp * pow(10,p);
		p++;

	}
	return ans;
}
char* dectoother(int num)
{
	int base=2;
	int i =0,rem,tmp,p =0 ,r=0;
	char ans[15];
	while(num>0)
	{
		//rem = num %10;
		tmp = num %base;
		if(tmp > 9)
			tmp+=39;
		tmp +=48;
		//printf("%c\n", tmp);
		ans[i] = tmp;
		i++;

		num/=base;

	}
	//ans[i] = '\0';
	r = 4-(i)%4;
	while(r>0 && r<4)
	{
		ans[i] = '0';
		r--;
		i++;
	}
	ans[i] = '\0';
	rev(ans);
	return ans;

}