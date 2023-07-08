#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
printf("starting process %d",getpid());
printf("\nexiting process\n");
exit(0);
printf("exited");
return(0);
}