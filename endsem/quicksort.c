#include <stdio.h>

int partition(int arr[], int low, int high)
{
	int i = low -1 ;
	int pivot  = arr[high];
	int j = low;
	int tmp;
	for(j = low; j<high; j++)
	{
		if(arr[j]<= pivot)
		{
			i++;
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
	tmp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = tmp;

	return (i+1);
}



int quicksort(int arr[], int low, int high)
{
	if(low<high)
	{
		int pi = partition(arr, low, high);

		quicksort(arr, low, pi-1);
		quicksort(arr, pi+1, high);
	}

}



int main(int argc, char const *argv[])
{
	int A[] = {4,3,2,1};
	quicksort(A,0,3);
	printf("The sorted array is:\n");
	int i;
	for(i=0;i<=3;i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}