#include <stdio.h>

void heapify(int arr[], int n , int i)
{
	int largest = i;
	int tmp;
	int l = 2*i +1;
	int r = 2*i +2;
	if(l < n && arr[l]>arr[largest])
		largest = l;
	if(r < n && arr[r] > arr[largest])
		largest = r;
	if(largest != i)
	{
		tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;
	
		heapify(arr, n ,largest);
	}

}





void heapsort(int arr[], int n)
{
	int i, tmp,j;
	printf("check\n");
	for(i= n;i>=0;i--)
		heapify(arr, n ,i);
	
	// for(i = n; i>=0 ; i--)
	// {
	// 	printf("%d iteration\n", n-i);
	// 	for(j=0;j<=n;j++)
	// 		printf("%d ", arr[j]);
	// 	printf("\n");
	// 	tmp = arr[i];
	// 	arr[i] = arr[0];
	// 	arr[0] = tmp;
	// 	printf("swap\n");
	// 	for(j=0;j<=n;j++)
	// 		printf("%d ", arr[j]);
	// 	printf("\n");
	// 	heapify(arr, i, 0);
	// }
}

int main(int argc, char const *argv[])
{
	int  A[] = {3,2,1,4,6,5};
	heapsort(A, 5);
	printf("The sorted array is:\n");
	int i;
	for(i=0;i<=5;i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}