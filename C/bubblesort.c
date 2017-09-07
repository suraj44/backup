#include <stdio.h>
main()
{
	int i=0, *ptr, j=0, tmp, n =0,t, swap = 0;
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
	t = n-1;
	for(i=0; i<n;i++)
	{
		j= 0 ;
		swap = 0;
		for(;j<t;j++)
		{
			if (*(ptr+j)>*(ptr + j +1))
			{
				tmp  = *(ptr+j);
				*(ptr + j ) = *(ptr + j+1);
				*(ptr + j +1) = tmp;
				swap+=1;	
			}  

		}
		t--;
		if (swap==0)
			break;
	}
	for(i=0; i<n;i++) 
	{
		printf("%d\n", *ptr);
		
		ptr++;
	}
}