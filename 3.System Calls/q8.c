#include<stdio.h>
#include<dirent.h>
void main()
{
DIR* dr=opendir("dir");
if(dr==NULL)
printf("could not open directory\n");
else
printf("directory ’dir’ opened\n");
}
