#include <stdio.h>
struct process{
	int pid,arrival,burst,tat,ct,wt,done;
}p[10];
int order[10];
void display(int n){
	int i,j;
	printf("\n---------------------------------------------------------------------------------");
	printf("\nPID \t Arrival \tBurst Time \tCompletion \tTurnaround \tWaiting");
	printf("\n---------------------------------------------------------------------------------");
	for(i=0;i<n;i++){
	printf("\nP%d \t %d \t\t %d \t\t %d \t\t %d \t\t %d",p[i].pid,p[i].arrival,p[i].burst,p[i].ct,p[i].tat,p[i].wt);
	}
	printf("\n---------------------------------------------------------------------------------\n");
}
void sort(int n){
	int i,j;
	struct process temp;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(p[j].arrival>p[j+1].arrival){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
}
void calc(int n){
	int time=p[0].arrival,i=0,j=0,k;
	while(i<n){
		time=time+p[j].burst;
		p[j].ct=time;
		p[j].done=1;
		p[j].tat=p[j].ct-p[j].arrival;
		p[j].wt=p[j].tat-p[j].burst;
		order[i]=j;
		//printf("\n%d ",time);
		int min;
		for(k=0;k<n;k++){
			if(p[k].arrival<=time&&p[k].done!=1)
				min=k;
		}
		for(k=0;k<n;k++){
			if(p[k].arrival<=time&&p[k].burst<p[min].burst&&p[k].done!=1)
				min=k;
			//printf("min:%d ",min);
		}
		//printf("\nNext min:%d",min);
		j=min;
		i++;
	}
}
void gantt(int n){
	int i,j;
	// for(i=0;i<n;i++)
	// 	printf("%d ",order[i]);
	printf("\nGANTT CHART\n");
	for(i=0;i<n;i++){
		for(j=0;j<p[order[i]].burst;j++)
			printf("--");
		printf("--");
	}
	for(i=0;i<n;i++)
		printf("-");
	printf("\n|");
	for(i=0;i<n;i++){
		for(j=0;j<p[order[i]].burst;j++)
			printf(" ");
		printf("P%d",order[i]);
		for(j=0;j<p[order[i]].burst;j++)
			printf(" ");
		printf("|");
	}
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<p[order[i]].burst;j++)
			printf("--");
		printf("--");
	}
	for(i=0;i<n;i++)
		printf("-");
	printf("\n");

	float avgtat=0.0,avgwt=0.0;
	for(i=0;i<n;i++){
		avgtat=avgtat+p[i].tat;
		avgwt=avgwt+p[i].wt;
	}
	printf("\nAverage Turnaround Time: %f",(avgtat/n));
	printf("\nAverage Waiting Time: %f\n",(avgwt/n));
}
void main(){
	int n,i,j;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("Enter arrival times:\n");
	for(i=0;i<n;i++){
		p[i].pid=i;
		scanf("%d",&p[i].arrival);
	}
	printf("Enter burst times:\n");
	for(i=0;i<n;i++){
		scanf("%d",&p[i].burst);
	}
	sort(n);
	calc(n);
	display(n);
	gantt(n);

}