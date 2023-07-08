#include <stdio.h>

void initialize(int a[],int b[]){
	for(int i=0;i<10;i++){
		a[i]=0;
		b[i]=-1;
	}
}
void firstfit(){
	int m,n,i,j;
	printf("Enter the number of blocks : ");
	scanf("%d",&m);
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int blockSize[10],processSize[10],blockAllocated[10],blockNoAlloc[10];
	printf("Enter the block size of each block : ");
	for(i=0;i<m;i++){
		printf("Block %d - ",i);
		scanf("%d",&blockSize[i]);
	}
	printf("Enter the process size of each process : \n");
	for(i=0;i<n;i++){
		printf("Process %d - ",i);
		scanf("%d",&processSize[i]);
	}
	initialize(blockAllocated,blockNoAlloc);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(blockAllocated[j]==0 && blockSize[j]>=processSize[i]){
				blockAllocated[j]=1;
				blockNoAlloc[i]=j;
				break;
			}
		}
	}
	printf("\nprocess no.|process size|allocated block|allocated block size|internal fragmentation\n");
	for(int i=0;i<n;i++){ 
	int j=blockNoAlloc[i];
	int s=processSize[i];
	int frag=blockSize[j]-processSize[i];
	if(blockNoAlloc[i]!=-1)
		printf(" %d\t\t%d\t\t%d\t\t%d\t\t %d\n",i,s,j,blockSize[j],frag);
	else
	printf(" %d\t\t%d\t\t--\t\t--\t\t --\n",i,s);
	}
}
void bestfit(){
	int m,n,i,j;
	printf("Enter the number of blocks : ");
	scanf("%d",&m);
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int blockSize[10],processSize[10],blockAllocated[10],blockNoAlloc[10];
	printf("Enter the block size of each block : ");
	for(i=0;i<m;i++){
		printf("Block %d - ",i);
		scanf("%d",&blockSize[i]);
	}
	printf("Enter the process size of each process : \n");
	for(i=0;i<n;i++){
		printf("Process %d - ",i);
		scanf("%d",&processSize[i]);
	}
	initialize(blockAllocated,blockNoAlloc);
	int mindiff,diff;
	int k,l;
	for(i=0;i<n;i++){
		mindiff=1000;
		for(j=0;j<m;j++){
			if(blockAllocated[j]==0 && blockSize[j]>=processSize[i]){
				diff=blockSize[j]-processSize[i];
				if(diff<mindiff){
					mindiff=diff;
					k=i;
					l=j;
				}
			}
		}
		if(mindiff==1000){
			continue;
		}
		blockAllocated[l]=1;
		blockNoAlloc[k]=l;
	}
	printf("\nprocess no.|process size|allocated block|allocated block size|internal fragmentation\n");
	for(int i=0;i<n;i++){ 
	int j=blockNoAlloc[i];
	int s=processSize[i];
	int frag=blockSize[j]-processSize[i];
	if(blockNoAlloc[i]!=-1)
		printf(" %d\t\t%d\t\t%d\t\t%d\t\t %d\n",i,s,j,blockSize[j],frag);
	else
	printf(" %d\t\t%d\t\t--\t\t--\t\t --\n",i,s);
	}
}
void worstfit(){
	int m,n,i,j;
	printf("Enter the number of blocks : ");
	scanf("%d",&m);
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	int blockSize[10],processSize[10],blockAllocated[10],blockNoAlloc[10];
	printf("Enter the block size of each block : ");
	for(i=0;i<m;i++){
		printf("Block %d - ",i);
		scanf("%d",&blockSize[i]);
	}
	printf("Enter the process size of each process : \n");
	for(i=0;i<n;i++){
		printf("Process %d - ",i);
		scanf("%d",&processSize[i]);
	}
	initialize(blockAllocated,blockNoAlloc);
	int maxdiff,diff;
	int k,l;
	for(i=0;i<n;i++){
		maxdiff=-1;
		for(j=0;j<m;j++){
			if(blockAllocated[j]==0 && blockSize[j]>=processSize[i]){
				diff=blockSize[j]-processSize[i];
				if(diff>maxdiff){
					maxdiff=diff;
					k=i;
					l=j;
				}
			}
		}
		if(maxdiff==-1){
			continue;
		}
		blockAllocated[l]=1;
		blockNoAlloc[k]=l;
	}
	printf("\nprocess no.|process size|allocated block|allocated block size|internal fragmentation\n");
	for(int i=0;i<n;i++){ 
	int j=blockNoAlloc[i];
	int s=processSize[i];
	int frag=blockSize[j]-processSize[i];
	if(blockNoAlloc[i]!=-1)
		printf(" %d\t\t%d\t\t%d\t\t%d\t\t %d\n",i,s,j,blockSize[j],frag);
	else
	printf(" %d\t\t%d\t\t--\t\t--\t\t --\n",i,s);
	}
}
void main(){
	printf("-----MEMORY ALLOCATION METHODS-----\n");
	printf("MENU\n\n");
	printf("1-FIRST - FIT\n");
	printf("2-BEST - FIT\n");
	printf("3-WORST - FIT\n");
	printf("4-EXIT\n");
	do{
		int choice;
		printf("Enter your choice : ");
		scanf("%d",&choice);
		if(choice==4){
			break;
		}
		switch(choice){
			case 1 :

			firstfit();
			break;

			case 2 :

			bestfit();
			break;

			case 3 :

			worstfit();
			break;

			default :
			printf("Invalid choice number!\n");
		}
	}while(1);
}