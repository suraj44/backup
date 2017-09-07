#include <stdio.h>
main()
{
	int * ptr;
	int n;
	int i,j,flag = 1,t1;
	printf("Enter the dimension of the square matrix\n");
	scanf("%d", &n);
	ptr = (int*)malloc(n*n*sizeof(int));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter element [%d] [%d]\n", (i), (j));
			scanf("%d", (ptr+i*n+j)); 
		}
	}
	t1 = *ptr;
	for(i=0;i<n;i++)
	{
		for(j=0 ; j<n ;j++)
		{
			if(i<=j)
			{
				if(*(ptr + i*n +j) != t1)
					{	
					printf("Error :%d %d\n", i ,j );
					flag = 0;
					break;
					}
			}
		if(!flag)
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ", *(ptr+i*n+j));
		}
		printf("\n");
	}
	printf("flag %d\n", flag);
	if(flag)
		printf("upper triangular matrix\n");
	else
		printf("not upper triangular matrix\n");

}
