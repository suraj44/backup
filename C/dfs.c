#include <stdio.h>
int a[20][20], stack[20],printed[20], stack1[20],visited[20], n, i, j, top=-1,t1 =0;

void dfs(int v) {
	
	int flag =1;
		//printf("%d ->", v);
	visited[v] =1;
	for(i = 1; i <= n; i++)
		if(a[v][i] && !visited[i])
		{
			flag = 0;
			stack[++top] = i;
			if(top>=0) 
			{
				dfs(stack[top]);
	
			}	
		}
	if(flag && !printed[v])
	{
		printed[v] =1;
		printf("%d ", v);
	}
	
	
}


int main() {
	int v, l;
	printf("\n Enter the number of vertices:");
	scanf("%d", &n);
	
	for(i=1; i <= n; i++) {
		stack[i] = 0;
		visited[i] = 0;
	}
	
	printf("\n Enter graph data in matrix form:\n");
	for(i=1; i<=n; i++) {
		for(j=1;j<=n;j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for(i=1;i<=n;i++)
	{
		visited[i] = 0;
		printed[i]= 0;
	}
	for(l=1;l<=n;l++)
	{
		if(!visited[l])
		{

			stack[++top] = l;
			dfs(stack[top]);	
			while(top>=0)
			{
				dfs(stack[top--]);
			}
		}
		
	}
	printf("\n");
	//stack[++top] = v;
	// for(i=1;i<=n;i++)
	// {
	// 	printf("visited\n");
	// 	for(j=1;j<=3;j++)
	// 		printf("%d ", visited[j]);
	// 	printf("\n");

	// 	if(!visited[i])
	// 	{

	// 		stack[++top] = i;
	// 		//printf("%d", i);
	// 		dfs(i);
	// 		while(top>=0)
	// 		{
	// 			dfs(stack[top--]);
	// 		}
	// 		//printf("\n");
	// 	}
	// }
	
	printf("\n");
	return 0;
	
}