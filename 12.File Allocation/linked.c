#include<stdio.h>
#include<stdlib.h>
typedef struct block{
int blockno;
struct block *next;
}block;

typedef struct{
int startblock;
int length;
block *list;
}file;
void main()
{
int n;
printf("\nNumber of free blocks:");
scanf("%d",&n);
int blocks[100];
for(int i=0;i<n;i++)
blocks[i]=0;
char ch='y';
do
{
file *ptr=(file*)malloc(sizeof(file));
printf("\nStarting Block:");
scanf("%d",&(ptr->startblock));
printf("\nFile Length:");
scanf("%d",&(ptr->length));
if(blocks[ptr->startblock]==1)
	printf("\nBlock already allocated");
else
{
block *b=(block*)malloc(sizeof(block));
b->blockno=ptr->startblock;
b->next=NULL;
ptr->list=b;
blocks[ptr->startblock]=1;
int count=1,i;
for(i=0;(i<n)&&(count<(ptr->length));i++)
{
if(blocks[i]==0)
{
block *new=(block*)malloc(sizeof(block));
new->blockno=i;
new->next=NULL;
block *p=ptr->list;
while(p->next!=NULL)
{
p=p->next;
}
p->next=new;
count++;
blocks[i]=1;
}
}
if(i==n&&count<(ptr->length))
{
printf("\nINSUFFICIENT STORAGE!");
}
else
{
printf("\nFile Allocation:\n");
block *p=ptr->list;
while(p->next!=NULL)
{
printf("%d->",p->blockno);
p=p->next;
}
printf("%d",p->blockno);
}
}
printf("\nContinue y/n?: ");
    scanf(" %c", &ch);
}while(ch!='n');
}