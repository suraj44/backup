#include <stdio.h>

int* isort(int*);
main()
{
	int a[5] = {5,4,3,2,1};
	int i;
	int tmp;
	int j;
	for(i=1;i<5;i++)
	{
		tmp = a[i];
		j = i-1;
		while(tmp <a[j] && j>=0)
		{
			a[j+1] = a[j];
			j--;


		}
		a[j+1] = tmp;
	}

	for(i=0;i<5;i++)
	{
		printf("%d", a[i]);
	}
}
