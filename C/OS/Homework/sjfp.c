#include <stdio.h>

struct process{
	int burst;
	int b1;
	int wait;
	int arrival;
	int  flag;
	int turnaround;
};
int main(int argc, char const *argv[])
{
	int n,i,j,tmp;
	float wait = 0, turnaround = 0;
	printf("Enter the number of processes\n");
	scanf("%d", &n);
	struct process list[10];
	for(i=0;i<n;i++)
	{
		printf("Enter burst time of process %d: ", i+1);
		scanf("%d", &list[i].burst);
		list[i].b1 = list[i].burst;
		list[i].flag = 1;
	}
	for(i=0;i<n;i++)
	{
		printf("Enter arrival time of process %d: ", i+1);
		scanf("%d", &list[i].arrival);
	}


	int time =0,min,count=0,temp,end;

	for(time=0;count!=n;time++)
	{
		min = 999;
		for(i=0;i<n;i++)
		{
			if(list[i].arrival<=time && list[i].burst<min && list[i].burst>0)
			{
				min = list[i].burst;
				temp = i;
			}

		}
		//printf("%d\n", temp);
		//printf("hey there\n");
		//list[temp].flag = 0;
		list[temp].burst--;

		if(list[temp].burst==0)
		{
			count++;
			end = time+1;
			list[temp].wait = end- list[temp].arrival - list[temp].b1;
			list[temp].turnaround = end - list[temp].arrival;
		}
	}
	for(i=0;i<n;i++)
	{
		wait+= list[i].wait;
		turnaround += list[i].turnaround;
	}
	//wait-=1;
	//turnaround-=1;
	wait/=n;
	turnaround/= n;
	printf("Process ID    Burst Time    Waiting Time     Turnaround time\n");
	for(i=0;i<n;i++)
	{
		printf("%d             %d             %d                %d\n", (i+1), list[i].b1, list[i].wait, list[i].turnaround);
	}	
	printf("\nAverage waiting time: %f \nAverage turnaround time: %f\n" , wait, turnaround);
	

	return 0;
}