#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int fd=open("a.txt",O_WRONLY|O_CREAT);
printf("file a.txt opened with file descriptor:%d",fd);
char str[100];
printf("\ninput a string to write to file a.txt: ");
scanf("%s",str);
write(fd,str,strlen(str));
printf("data written to file a.txt");
close(fd);
fd=open("a.txt",O_RDONLY);
char bfr[100];
int len=read(fd,bfr,10);
bfr[len]='\0';
printf("\ndata read from file a.txt: %s",bfr);
close(fd);
printf("\nfile a.txt closed\n");
}