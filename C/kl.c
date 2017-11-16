//Program to find the kth smallest element in an unsorted array
#include <stdio.h>
main()
{
	int *a,n,i,flag =1,k,max=-100000,j,tmp;
	printf("Enter the number of elements in the array\n");
	scanf("%d", &n);
	printf("Enter 'k':\n");
	scanf("%d",&k);
	if(k>n)
	{
		printf("Invalid k\n");
		flag = 0;
	}
	if (flag)
	{
	a =(int*)malloc(n*sizeof(int));
	printf("Enter %d elements:\n", n);
	for(i=0;i<n;i++)
	{
		scanf("%d", a);
		a++;
	}
	a-=n;
	tmp = k;
	for(i=0;i<n;i++)
	{
		if(*(a+i)>max)
			max = *(a+i);
			j = i;
			tmp--;
		if(!tmp)
			break;
	}
	printf("The %d smallest element of the array is %d\n", k ,*(a+j));
	}

}
