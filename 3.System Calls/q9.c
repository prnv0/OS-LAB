#include<stdio.h>
#include<dirent.h>
void main()
{
DIR* dr=opendir("dir");
if(dr==NULL)
printf("could not open directory\n");
else
{
printf("directory ’dir’ opened\n");
struct dirent* de;
printf("contents of the directory are:\n");
while((de=readdir(dr))!=NULL)
{
printf("%s\n",de->d_name);
}
}
}