#include <stdio.h>

typedef struct process
{
	int pid, arrival, burst, wait, turn;
} process;

void sort(process *p, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (p[min].arrival > p[j].arrival)
			min = j;
		}
		if (i != min)
		{
			process temp = p[i];
			p[i] = p[min];
			p[min] = temp;
		}
	}
}

void fcfs(process *p, int n)
{
	p[0].wait = 0;
	p[0].turn=p[0].burst;
	int sum=p[0].arrival;
	for (int i = 1; i < n; i++)
	{
		sum+=p[i-1].burst;
		p[i].wait = sum-p[i].arrival;
		if(p[i].wait<0)
		//
		p[i].wait=0;
		p[i].turn = p[i].burst + p[i].wait;
	}
}


void gantt_chart(process *p,int n)
{
	printf("\n");
	for (int i = 0; i < p[n-1].turn - 1; i++)
	{
		printf(" ");
	}

	printf("GANTT CHAR\n ");
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p[i].burst; j++)
		printf("--");
		printf(" ");
	}
	printf("\n|");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p[i].burst - 1; j++)
		printf(" ");
		printf("P%d", i + 1);
		for (j = 0; j < p[i].burst - 1; j++)
		printf(" ");
		printf("|");
	}
	printf("\n ");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p[i].burst; j++)
		printf("--");
		printf(" ");
	}
	printf("\n%d",p[0].arrival);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p[i].burst; j++)
		printf("  ");
		if (p[i].turn+p[i].arrival > 9)
		printf("\b");
		printf("%d", p[i].turn+p[i].arrival);
	}
	printf("\n");
	
}


void average(process *p,int n)
{
	float sumw = 0, sumt = 0;
	for (int i = 0; i < n; i++)
	{
		sumw += p[i].wait;
		sumt += p[i].turn;
	}
	printf("\nAverage Waiting Time = %0.3f", sumw / n);
	printf("\nAverage Turnaround Time = %0.3f\n", sumt / n);
}
void main()
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	process p[10];

	printf("Enter the arrival times of Processes:");
	for (int i = 0; i < n; i++)
	scanf("%d", &p[i].arrival);
	printf("Enter the burst times of Processes:");

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i].burst);
		p[i].pid = i + 1;
	}

	sort(p, n);
	fcfs(p, n);
	printf("\n-----------------------------------------------------------------------\n");
	printf("Processes\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i = 0; i < n; i++)
	{
		printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].arrival, p[i].burst, p[i].wait,p[i].turn);
	}
	printf("\n\n");
	gantt_chart(p,n);
	average(p, n);
}
