#include <stdio.h>
#include <stdlib.h>
int f = -1, r = -1;
int idx = -1;
#define max 30
typedef struct process
{
	int pid, at, bt, brt, priority, ct, tat, wt, temp;
} process;
process queue[30];
struct gantt
{
	int pid, starttime;
} s[30];

void insertGantt(int id, int start)
{
	idx++;
	s[idx].pid = id;
	s[idx].starttime = start;
}
void enqueue(process queue[], process item)
{
	if (r == max - 1)
	{
		printf("Queue full!\n");
		return;
	}
	r++;
	queue[r] = item;
}
int dequeue(process queue[])
{
	if (f == r)
	{
		printf("Queue empty!\n");
		return -1;
	}
	f++;
	return queue[f].pid;
}
void initialize(int completed[], int visited[], int present[], int n)
{
	for (int i = 0; i < n; i++)
	{
		completed[i] = 0;
		visited[i] = 0;
		present[i] = 0;
	}
}
void initialize_gantt()
{
	for (int i = 0; i < 30; i++)
	{
		s[i].pid = 0;
		s[i].starttime = 0;
	}
}
void arrivalSort(process *p, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (p[j].at > p[j + 1].at)
			{
				process temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}
void computeTurnWait(process *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}
}
void fcfs(process *p, int n)
{
	int sum = p[0].at;
	insertGantt(p[0].pid, sum);
	for (int i = 0; i < n; i++)
	{
		insertGantt(p[i].pid, sum);
		sum += p[i].bt;
		p[i].ct = sum;
		insertGantt(p[i].pid, sum);
	}
	computeTurnWait(p, n);
}
void sjf(process *p, int n, int visited[], int completed[])
{
	int sumbt = 0, i, minbt, k = 0;
	for (i = 0; i < n; i++)
	{
		sumbt += p[i].bt;
	}
	int t = p[0].at;
	insertGantt(p[0].pid, t);
	while (t < sumbt)
	{
		for (i = 0; i < n; i++)
		{
			if (p[i].at <= t && completed[i] == 0)
			{
				visited[i] = 1;
			}
		}
		minbt = 999;
		for (i = 0; i < n; i++)
		{
			if (visited[i] && completed[i] == 0)
			{
				if (p[i].bt < minbt)
				{
					minbt = p[i].bt;
					k = i;
				}
			}
		}
		insertGantt(p[k].pid, t);
		t += p[k].bt;
		p[k].ct = t;
		completed[k] = 1;
		visited[k] = 0;
	}
	insertGantt(p[k].pid, t);
	computeTurnWait(p, n);
}
void srtf(process *p, int n, int visited[], int completed[])
{
	int sumbt = 0, i, minbrt, k = 0;
	for (i = 0; i < n; i++)
	{
		sumbt += p[i].bt;
	}
	int t = p[0].at;
	insertGantt(p[0].pid, t);
	while (t < sumbt)
	{
		for (i = 0; i < n; i++)
		{
			if (p[i].at <= t && completed[i] == 0)
			{
				visited[i] = 1;
			}
		}
		minbrt = 999;
		for (i = 0; i < n; i++)
		{
			if (visited[i] && completed[i] == 0)
			{
				if (p[i].brt < minbrt)
				{
					minbrt = p[i].brt;
					k = i;
				}
			}
		}
		p[k].brt--;
		insertGantt(p[k].pid, t);
		if (p[k].brt == 0)
		{
			completed[k] = 1;
			visited[k] = 0;
			p[k].ct = t + 1;
		}
		t++;
	}
	insertGantt(p[k].pid, t);
	computeTurnWait(p, n);
}
void priority(process *p, int n, int visited[], int completed[])
{
	int sumbt = 0, i, maxpriority, k = 0;
	for (i = 0; i < n; i++)
	{
		sumbt += p[i].bt;
	}
	int t = p[0].at;
	insertGantt(p[0].pid, t);
	while (t < sumbt)
	{
		for (i = 0; i < n; i++)
		{
			if (p[i].at <= t && completed[i] == 0)
			{
				visited[i] = 1;
			}
		}
		maxpriority = 0;
		for (i = 0; i < n; i++)
		{
			if (visited[i] && completed[i] == 0)
			{
				if (p[i].priority > maxpriority)
				{
					maxpriority = p[i].priority;
					k = i;
				}
			}
		}
		insertGantt(p[k].pid, t);
		t += p[k].bt;
		p[k].ct = t;
		completed[k] = 1;
		visited[k] = 0;
	}
	insertGantt(p[k].pid, t);
	computeTurnWait(p, n);
}
void pre_priority(process *p, int n, int visited[], int completed[])
{
	int sumbt = 0, i, maxpriority, k = 0;
	for (i = 0; i < n; i++)
	{
		sumbt += p[i].bt;
	}
	int t = p[0].at;
	insertGantt(p[0].pid, t);
	while (t < sumbt)
	{
		for (i = 0; i < n; i++)
		{
			if (p[i].at <= t && completed[i] == 0)
			{
				visited[i] = 1;
			}
		}
		maxpriority = 0;
		for (i = 0; i < n; i++)
		{
			if (visited[i] && completed[i] == 0)
			{
				if (p[i].priority > maxpriority)
				{
					maxpriority = p[i].priority;
					k = i;
				}
			}
		}
		p[k].brt--;
		insertGantt(p[k].pid, t);
		if (p[k].brt == 0)
		{
			completed[k] = 1;
			visited[k] = 0;
			p[k].ct = t + 1;
		}
		t++;
	}
	insertGantt(p[k].pid, t);
	computeTurnWait(p, n);
}
void roundRobin(process *p, int n, int visited[], int completed[], int present[], int timeslice)
{
	int i, pr = 0, sumbt = 0;
	for (i = 0; i < n; i++)
	{
		sumbt += p[i].bt;
	}
	int t = p[0].at;
	insertGantt(p[0].pid, t);
	while (t < sumbt)
	{
		for (i = 0; i < n; i++)
		{
			if (p[i].at <= t && completed[i] == 0 && present[i] == 0)
			{
				visited[i] = 1;
				enqueue(queue, p[i]);
				present[i] = 1;
			}
		}
		if (pr != 0 && p[pr - 1].brt != 0)
			enqueue(queue, p[pr - 1]);
		pr = dequeue(queue);
		if (p[pr - 1].brt <= timeslice && completed[pr - 1] == 0)
		{
			insertGantt(p[pr - 1].pid, t);
			while (p[pr - 1].brt > 0)
			{
				p[pr - 1].brt--;
				t++;
			}
			p[pr - 1].ct = t;
			completed[pr - 1] = 1;
			visited[pr - 1] = 0;
		}
		else
		{
			p[pr - 1].brt -= timeslice;
			insertGantt(p[pr - 1].pid, t);
			t += timeslice;
		}
	}
	insertGantt(p[pr - 1].pid, t);
	computeTurnWait(p, n);
}
void computeAverage(process *p, int n)
{
	int sumtat = 0;
	int sumwt = 0;
	for (int i = 0; i < n; i++)
	{
		sumtat += p[i].tat;
		sumwt += p[i].wt;
	}
	printf("Average TurnAround Time = %.2f\n", (double)sumtat / n);
	printf("Average Waiting Time = %.2f\n", (double)sumwt / n);
}
void display(process *p, int n)
{
	printf("Process no   Arrival Time  Burst Time  Completion Time  TurnAround Time  Waiting Time\n\n");

	for (int i = 0; i < n; i++)
	{
		printf("    %d            %2d           %2d             %2d              %2d               %2d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
	}
	printf("\n");
}
void gantt_chart()
{
	int i = 0;
	printf("-----");
	while (s[i + 1].pid != 0)
	{
		if (s[i].pid != s[i + 1].pid)
		{
			printf("------");
		}
		else
			printf("-");
		i++;
	}
	printf("-\n");
	i = 0;
	printf("| P%d ", s[i].pid);
	while (s[i + 1].pid != 0)
	{
		if (s[i].pid != s[i + 1].pid)
		{
			printf(" | P%d ", s[i + 1].pid);
		}
		else
			printf(" ");
		i++;
	}
	printf("|\n");
	i = 0;
	printf("-----");
	while (s[i + 1].pid != 0)
	{
		if (s[i].pid != s[i + 1].pid)
		{
			printf("------");
		}
		else
			printf("-");
		i++;
	}
	printf("-\n");
	i = 0;
	printf("%-2d   ", s[i].starttime);
	while (s[i + 1].pid != 0)
	{
		if (s[i].pid != s[i + 1].pid)
		{
			printf(" %-2d   ", s[i + 1].starttime);
		}
		else
			printf(" ");
		i++;
	}
	printf("%-2d\n", s[i].starttime);
}
void main()
{
	process p[20];
	int visited[20], completed[20], present[20], timeslice;
	printf("-----CPU SCHEDULING ALGORITHMS-----\n");
	printf("MENU\n\n");
	printf("1-FIRST COME FIRST SERVE\n");
	printf("2-SHORTEST JOB FIRST\n");
	printf("3-SHORTEST REMAINING TIME FIRST\n");
	printf("4-PRIORITY NON-PRE-EMPTIVE\n");
	printf("5-PRIORITY PRE-EMPTIVE\n");
	printf("6-ROUND ROBIN\n");
	printf("7-EXIT\n");
	do
	{
		printf("Enter your choice : ");
		int choice;
		scanf("%d", &choice);
		if (choice == 7)
		{
			break;
		}
		printf("Enter the number of processes : ");
		int n;
		scanf("%d", &n);
		printf("Enter the arrival time of the processes : ");
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &p[i].at);
		}
		printf("Enter the burst time of the processes : ");
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &p[i].bt);
			p[i].brt = p[i].bt;
			p[i].pid = i + 1;
		}
		idx = -1;
		switch (choice)
		{
		case 1:
			initialize(completed, visited, present, n);
			initialize_gantt();
			arrivalSort(p, n);
			fcfs(p, n);
			display(p, n);
			computeAverage(p, n);
			gantt_chart();
			break;

		case 2:
			initialize(completed, visited, present, n);
			initialize_gantt();
			arrivalSort(p, n);
			sjf(p, n, visited, completed);
			display(p, n);
			computeAverage(p, n);
			gantt_chart();
			break;

		case 3:
			initialize(completed, visited, present, n);
			initialize_gantt();
			arrivalSort(p, n);
			srtf(p, n, visited, completed);
			display(p, n);
			computeAverage(p, n);
			gantt_chart();
			break;

		case 4:
			printf("Enter the priority of the processes : ");
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &p[i].priority);
			}
			initialize(completed, visited, present, n);
			initialize_gantt();
			arrivalSort(p, n);
			priority(p, n, visited, completed);
			display(p, n);
			computeAverage(p, n);
			gantt_chart();
			break;

		case 5:
			printf("Enter the priority of the processes : ");
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &p[i].priority);
			}
			initialize(completed, visited, present, n);
			initialize_gantt();
			arrivalSort(p, n);
			pre_priority(p, n, visited, completed);
			display(p, n);
			computeAverage(p, n);
			gantt_chart();
			break;

		case 6:
			printf("Enter time quantum : ");
			scanf("%d", &timeslice);
			initialize(completed, visited, present, n);
			initialize_gantt();
			arrivalSort(p, n);
			roundRobin(p, n, visited, completed, present, timeslice);
			display(p, n);
			computeAverage(p, n);
			gantt_chart();
			break;
		default:
			printf("Invalid choice number !\n");
		}
	} while (1);
}