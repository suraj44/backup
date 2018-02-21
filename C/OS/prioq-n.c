#include <stdio.h>

void insertionsort(int a[5][10], int n)
{
	int i ,j, t1, t2, t3, t4;

	for(i=1;i<n;i++)
	{
		t1 = a[0][i];
		t2 = a[1][i];
		t4 = a[3][i];
		j = i-1;
		while(j>=0 && a[1][j]>t3)
		{
			a[0][j+1] = a[0][j];
			a[1][j+1] = a[1][j];
			a[3][j+1] = a[3][j];
			j--;
		}
		a[0][j+1] = t1;
		a[1][j+1] = t2;
		a[3][j+1]= t4;

	}

}



int main(int argc, char const *argv[])
{
	int n,i,tmp;
	int process[6][10];
	int new[6][10];
	printf("Enter the number of processes\n");
	scanf("%d", &n);
	printf("Enter the CPU burst time for each process\n");
	int  turnaround[10];
	printf("\n\n\n");
	for(i=0;i<n;i++)
	{
		printf("Enter CPU burst time of process %d ", i+1);
		scanf("%d", &process[1][i]);
		process[0][i] = i+1;
	}
	int j, t1, t2, t3, t4;
	printf("Enter arrival times of each process\n");
	for(i=0;i<n;i++)
	{
		printf("Enter arrival time of process %d ", i+1);
		scanf("%d", &process[2][i]);
		
	}
	for(i=0;i<n;i++)
	{
		printf("Enter PRIORITY time of process %d ", i+1);
		scanf("%d", &process[5][i]);
		
	}

	/*for(i=1;i<n;i++)
	{
		t1 = process[0][i];
		t2 = process[1][i];
		t3= process[2][i];
		t4 = process[3][i];
		j = i-1;
		while(j>=0 && process[2][j]>t3)
		{
			process[0][j+1] = process[0][j];
			process[1][j+1] = process[1][j];
			process[3][j+1] = process[3][j];
			j--;
		}
		process[0][j+1] = t1;
		process[1][j+1] = t2;
		process[3][j+1]= t4;

	}*/
	//insertionsort(process,n);
	process[3][0]=  0;
	int time =0 ,done;
	int c =0,temp,min;
	for(i=0;i<n;i++)
	{
		process[4][i]=1;
	}
	while(1)
	{
		min = -1;
		temp = 0;
		for(i=0;i<n;i++)
		{
			printf("process: %d %d %d min:%d time: %d \n", process[1][i], process[2][i], process[4][i], min, time);
			if(process[5][i]> min && process[2][i]<=time && process[4][i]==1)
			{
				printf("HI THERE\n");
				min = process[5][i];
				temp = i;
				

			}
		}
		process[4][temp]=  0;
		printf("%d\n", process[4][3]);
		printf("%d\n", process[0][temp]);
		new[0][c]= process[0][temp];
		new[1][c] = process[1][temp];
		new[2][c] = process[2][temp];
		new[3][c] = process[3][temp];
		new[4][c] = process[4][temp];
		new[5][c] = process[5][temp];
		c+=1;
		process[3][temp]= time - process[2][temp];
		if (process[3][temp]<0)
			process[3][temp] = 0;
		
		time+=process[1][temp];
		if(c==n)
			break;
		
	}
	int s =new[1][0];
	for(i=1;i<n;i++)
	{
		
		new[3][i] = s - new[2][i];
		s+= new[1][i];
	}
	int w=0,t=0;
	for(i=0;i<n;i++)
	{
		turnaround[i] = new[3][i] + new[1][i];
		w+= new[3][i];
		t+=turnaround[i];
	}
	;
	printf("Process ID    Burst Time    Waiting Time     Turnaround time\n");
	for(i=0;i<n;i++)
	{
		printf("%d             %d             %d                %d\n", new[0][i], new[1][i], new[3][i], turnaround[i]);
	}	
	printf("\nAverage waiting time: %f \nAverage turnaround time: %f\n" , (float) w/n, (float) t/n);
	return 0;


}