#include<stdio.h>
#include<unistd.h>
void main()
{
printf("process running\n");
int pid=getpid();
printf("process id of running process:%d\n",pid);
}