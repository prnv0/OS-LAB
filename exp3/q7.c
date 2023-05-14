#include<stdio.h>
#include<sys/stat.h>
void main()
{
struct stat sfile;
stat("a.txt",&sfile);
printf("size of file a.txt: %ld\n",sfile.st_size);
printf("mode of file a.txt: %o\n",sfile.st_mode);
printf("id of device in which a.txt resides: %ld\n",sfile.st_dev);
}