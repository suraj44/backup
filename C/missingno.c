#include <stdio.h>
#include <stdlib.h>
main()
{
	int n,i,tmp,s1;
	printf("Enter 'n-1': ");
	scanf("%d", &n);
	tmp = n*(n-1)/2;
	printf("Say our array is: \n");
	int flg = rand() %n-1;
	for(i=0;i<=n-1;i++)
	{
		if(i!= flg)
		{	
			printf("%d ",i);
			s1 += i;
	    }
	}
	printf("\n");
	//printf("%d %d\n",tmp,flg);
	printf("The missing number is %d\n", tmp-s1);
}