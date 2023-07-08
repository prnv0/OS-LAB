#include <stdio.h>
void main(){
int process_size[10],block_size[10],block_allocated[10],process_alloc[10];
int m,n;
printf("Input no. of blocks:");
scanf("%d",&m);
printf("Input no. of processes:");
scanf("%d",&n);
printf("Input block sizes:");
for(int i=0;i<m;i++){
	printf("\nblock %d:",i+1);
	scanf("%d",&block_size[i]);
}
printf("\ninput process sizes:");
for(int i=0;i<n;i++){
	printf("\nprocess %d:",i+1);
	scanf("%d",&process_size[i]);
}
for(int i=0;i<m;i++)
	block_allocated[i]=0;
for(int i=0;i<n;i++)
	process_alloc[i]=-1;
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(block_allocated[j]==0){
			if(block_size[j]>=process_size[i]){
				block_allocated[j]=1;
				process_alloc[i]=j;
				break;
			}
		}
	}
}
printf("\nprocesss no.|process size|allocated block|allocated block size|internal fragmentation\n");
for(int i=0;i<n;i++){
	int j=process_alloc[i];
	int s=process_size[i];
	int frag=block_size[j]-process_size[i];
	if(process_alloc[i]!=-1)
		printf("%d\t\t%d\t\t%d\t\t%d\t\t %d\n",i+1,s,j+1,block_size[j],frag);
	else
		printf("%d\t\t%d\t\t--\t\t--\t\t --\n",i+1,s);
}
}