#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
int fd=open("a.txt",O_RDONLY);
if(fd<0)
{
exit(0);
}
else
{
printf("file a.txt opened with file descriptor %d\n",fd);
char str[15];
int len=read(fd,str,10);
str[len]='\0';
printf("data read from a.txt:%s\n",str);
int e=close(fd);
if(e<0)
printf("close failed!\n");
else
printf("closed the file a.txt with file descriptor %d\n",fd);
}
}