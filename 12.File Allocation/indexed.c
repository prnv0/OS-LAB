#include<stdio.h>
#include<stdlib.h>
void main()
{
int n;
printf("\nNumber of blocks: ");
scanf("%d",&n);
int *blocks=(int*)malloc(sizeof(int));
for(int i=0;i<n;i++)
    blocks[i]=0;
char ch='y';
do
{
int index;
printf("\nIndex Block Number:");
scanf("%d",&index);
if(blocks[index]==1)
printf("\nIndex Full-No allocation possible");
else
{
int length;
printf("\nFile Length:");
scanf("%d",&length);
int count=0;
blocks[index]=1;
int indexblock[100];
for(int i=0;(i<n)&&(count<length);i++)
{
if(blocks[i]==0)
{
blocks[i]=1;
indexblock[count]=i;
count++;
}
}
if(count<length)
{
printf("\nInsufficient storage-No Allocation Possible");
for(int i=0;i<count;i++)
{
blocks[indexblock[i]]=0;
}
blocks[index]=0;
}
else
{
printf("\nAllocation:\n");
for(int i=0;i<count;i++)
printf("%d−>%d\n",index,indexblock[i]);
}
}
printf("Continue y/n?: ");
    scanf(" %c", &ch);
}while(ch!='n');
}