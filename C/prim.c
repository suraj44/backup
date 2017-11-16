#include <stdio.h>
#define V 10

int min(int key[], int mstset[],int n)
{
	int min = 9998;
	int i, ind;
	for(i=0 ;i<n;i++)
	{
		if(mstset[i] == 0 && key[i] < min)
		{
			min = key[i];
			ind = i;
		}
	}
	return ind;
}
void printprim(int parent[], int n, int graph[V][V])
{
	printf("Edge     Weight\n");
	int i;
	for(i=1;i<n;i++)
		printf("%d - %d  %d\n", parent[i],i,graph[i][parent[i]]);
}


void prim(int graph[V][V], int n)
{
	int i , count, u ,v;
	int parent[V]; //store spanning tree
	int key[V]; //find min weight in each iteration
	int mstset[V]; //boolean array

	for(i=0 ; i<n;i++)
	{
		key[i] = 9999; //setting every key to infinity
		mstset[i] = 0; //marking every node as NOT visited
	}

	key[0] = 0;
	parent[0]  = -1;

	for(count = 0;count< n-1; count++)
	{
		int u = min(key, mstset,n);
		mstset[u] = 1;
		for(v=0; v<n;v++)
		{
			if((graph[u][v]!=0 && mstset[v] == 0) && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}

		}
	}
	printprim(parent, n, graph);
}






int main() {
	int a[V][V], n, i ,j ;
	int v;
	printf("\n Enter the number of vertices:");
	scanf("%d", &n);
	
	printf("\n Enter graph data in matrix form:\n");
	for(i=1; i<=n; i++) {
		for(j=1;j<=n;j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	prim(a,n);
	// printf("\n Enter the starting vertex:");
	// scanf("%d", &v);
	// stack[++top] = v;
	
	
	printf("\n");
	printf("\n");
	return 0;
	
}