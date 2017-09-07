#include <stdio.h>
main()
{
	int i=0, *ptr, j=0, tmp, n =0,t, swap = 0, min =0,var;
	printf("Enter the number of elements in the array\n");
	scanf("%d", &n);
	ptr = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("Enter element %d\n", (i+1));
		scanf("%d", &*ptr);
		ptr++;
	}
	ptr-=n;
	for(i=0 ; i<n-1 ; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
		{
			if(*(ptr+j) < *(ptr+min))
			{
				min = j;
			}
		}
		tmp = *(ptr+i);
		*(ptr + i) = *(ptr + min);
		*(ptr + min) = tmp;
	}
	for(i=0; i<n;i++) 
	{
		printf("%d\n", *ptr);
		
		ptr++;
	}

}