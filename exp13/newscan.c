#include <stdio.h>
#include <stdlib.h>
int pg[20];
int n;
void sort(){
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++){
			if(pg[j]>pg[j+1]){
				t=pg[j];
				pg[j]=pg[j+1];
				pg[j+1]=t;
			}
		}
}
int findloc(int head){
	for(int i=0;i<n;i++){
		if(head<pg[i])
			return i;
	}
}
void main(){
	int head,i,j,k,max;
	printf("Enter Number of Requests: ");
	scanf("%d",&n);
	printf("Enter Request Array: ");
	for(i=0;i<n;i++)
		scanf("%d",&pg[i]);
	printf("Enter Head Position: ");
	scanf("%d",&head);
	printf("Enter max: ");
	scanf("%d",&max);


	printf("Seek Sequence: ");
	if(pg[0]>head){
		sort();
		int pos=findloc(head);
		// printf("\n%d\n",pos);
		printf("%d ",head);
		for(i=pos;i<n;i++){
			printf("%d ",pg[i]);
		}
		printf("%d ",max);
		for(i=pos-1;i>=0;i--){
			printf("%d ",pg[i]);
		}
		printf("0\n");
	}
	else{
		sort();
		int pos=findloc(head);
		// printf("\n%d\n",pos);
		printf("%d ",head);
		for(i=pos-1;i>=0;i--){
			printf("%d ",pg[i]);
		}
		printf("0");
		for(i=pos;i<n;i++){
			printf("%d ",pg[i]);
		}
		printf("%d\n",max);
		
	}
	
}