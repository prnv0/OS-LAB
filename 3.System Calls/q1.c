#include<stdio.h>
#include<unistd.h>
int main()
{
int pid;
pid=fork();
if(pid>0)
printf("process %d creates child process %d\n",getpid(),pid);
return 0;
}