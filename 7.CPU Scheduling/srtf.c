#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct
{
    int pid;     // process ID
    int burst;   // Burst time of the process
    int arrival; // Arrival time of the process
    int wait;    // Waiting time of the process
    int turn;    // turnaround time o the process
} process;
void gantt(process *p, int *chart, int totTime, int start)
{
    printf("\n\n");
    printf("\tGANTT CHART\n\n ");
    int t, curr;
    t = start;
    curr = chart[t];
    int length[totTime], numCols = 0;
    int order[totTime];
    order[numCols] = curr;
    while (t <= totTime + start)
    {
        length[numCols] = 1;
        while (curr == chart[t])
        {
            length[numCols]++;
            t++;
        }
        order[numCols] = curr;
        numCols++;
        curr = chart[t];
        t++;
    }
    length[0]--; // the loop adds 1 extra for 1st iter
    // print top line
    for (int i = 0; i < numCols; i++)
    {
        for (int j = 0; j < length[i] + 1; j++)
            printf("--");
        printf(" ");
    }
    // print chart
    printf("\n|");
    for (int i = 0; i < numCols; i++)
    {
        for (int j = 0; j < length[i]; j++)
            printf(" ");
        printf("P%d", order[i]);
        for (int j = 0; j < length[i]; j++)
            printf(" ");
        printf("|");
    }
    // print bottom line
    printf("\n ");
    for (int i = 0; i < numCols; i++)
    {
        for (int j = 0; j < length[i] + 1; j++)
            printf("--");
        printf(" ");
    }
    printf("\n");
    // print time
    int time = start;
    printf("%d", start);
    for (int i = 0; i < numCols; i++)
    {
        for (int j = 0; j < length[i] + 1; j++)
            printf("  ");
        if (time > 9)
            printf("\b");
        time += length[i];
        printf("%d", time);
    }
    printf("\n");
}
void SRTF(process *p, int n, int totTime)
{
    int rem[n];
    for (int i = 0; i < n; i++)
        rem[i] = p[i].burst;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0;
    bool check = false;

    int chart[totTime];

    printf("\n");
    // Process until all processes gets completed
    bool started = false;
    int start;
    while (complete != n)
    {
        // Find process with minimum remaining time among the
        // processes that arrives till the current time`
        for (int j = 0; j < n; j++)
        {
            if (rem[j] > 0 && p[j].arrival <= t && rem[j] < minm)
            {
                if (!started)
                {
                    started = true;
                    start = t;
                }
                minm = rem[j];
                shortest = j;
                check = true;
            }
        }
        chart[t] = shortest + 1;
        if (check == false)
        {
            t++;
            continue;
        }
        rem[shortest]--; // Reduce remaining time by one

        minm = rem[shortest];
        if (minm == 0)
            minm = INT_MAX; // Update minimum

        // If a process gets completely executed
        if (rem[shortest] == 0)
        {
            complete++; // Increment complete
            check = false;

            // Find finish time of current process
            int finish_time = t + 1;

            // Calculate waiting time
            p[shortest].wait = finish_time - p[shortest].burst - p[shortest].arrival;

            if (p[shortest].wait < 0)
                p[shortest].wait = 0;
        }
        t++; // Increment time
    }
    for (int i = 0; i < n; i++)
    {
        p[i].turn = p[i].wait + p[i].burst;
    }
    gantt(p, chart, totTime, start);
}
void average(process *p, int n)
{
    int sumw = 0, sumt = 0;
    for (int i = 0; i < n; i++)
    {
        sumw += p[i].wait;
        sumt += p[i].turn;
    }
    printf("\n\nAverage Waiting Time = %0.3f", sumw / (float)n);
    printf("\nAverage Turnaround Time = %0.3f\n", sumt / (float)n);
}

void printProcessTable(process *p, int n)
{
    printf("\nProcesses\tArrival Burst Waiting Turnaround\n");
    for (int i = 0; i < n; i++)
        printf("  p%d\t\t % d\t %d\t %d\t %d\n", p[i].pid, p[i].arrival, p[i].burst, p[i].wait, p[i].turn);
}
int main(void)
{
    int n, totTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    process p[10];
    printf("Enter the arrival times of Processes:");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i].arrival);
    printf("Enter the burst times of Processes:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].burst);
        p[i].pid = i + 1;
        totTime += p[i].burst;
    }
    SRTF(p, n, totTime);
    printProcessTable(p, n);
    average(p, n);
}
	