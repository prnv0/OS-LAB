#include<stdio.h>
#include<stdlib.h>
void main()
{
int n;
printf("Number of Requests: ");
scanf("%d",&n);
int*request=(int*)malloc(n*sizeof(int));
printf("\nRequest Array: ");
for(int i=0;i<n;i++)
{
scanf("%d",&request[i]);
}
int head;
printf("\nHead Postion: ");
scanf("%d",&head);
int max;
printf("\nMax:");
scanf("%d",&max);
printf("\nSeek Sequence: ");
int seekcount=0;
for(int i=head;(i<=max)&&(n!=0);i++){
	int flag=0,j;
	for(j=0;j<n;j++){
		if(request[j]==i){
			flag=1;
			break;
		}
	}
	if(flag==1){
		printf("%d ",i);
		int distance=abs(i-head);
		seekcount+=distance;
		head=i;

		for(int k=j;k<n-1;k++){
			request[k]=request[k+1];
		}
		n--;
	}
}
if(n!=0){
	seekcount+=abs(max-head)+max;
	head=0;
	for(int i=0;(n!=0);i++){
		int flag=0,j;
		for(j=0;j<n;j++){
			if(request[j]==i){
				flag=1;
				break;
			}
		}
		if(flag==1){
			printf("%d ",i);
			int distance=abs(i-head);
			seekcount+=distance;
			head=i;
			for(int k=j;k<n-1;k++){
			request[k]=request[k+1];
			}
			n--;
		}
	}
}
printf("\nSeek Count:%d\n",seekcount);
}