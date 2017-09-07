#include <stdio.h>
main()
{
	int n,i,j,tmp;
	int final=0;
	int * ptr;
	printf("Enter the number of elements in the array\n");
	scanf("%d", &n);
	ptr = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("Enter element %d\n", (i+1));
		scanf("%d", (ptr+i));


	}

	for(i=0; i<n;i++)
	{

		j =i;
		tmp = 1;
		while(*(ptr+j+1)>*(ptr+j))
		{
			tmp ++;
			//printf("%d %d\n", *(ptr +j+1), *(ptr+j));
			//printf(" i - %d j- %d * - %d\n", i,j,*(ptr + j) );

			if(j==n-1)
				break;
			j++;

		}
		if(tmp>final)
			final = tmp;
	}
	printf("answer : %d\n", final);
}