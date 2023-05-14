#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
int pid=fork(); //creating child
if(pid<0)
{
printf("fork failed!\n");
}
else if(pid==0)
{
printf("\nchild process %d executing\n",getpid());
printf("calling program prg.c from child using exec\n");
char* argv[]={"prg",NULL};
execv("./prg",argv);
}
else
{
printf("parent process %d executing\n",getpid());
printf("Hi\n");
}
}