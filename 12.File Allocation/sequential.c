#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>

void recurse(int files[]){
    int flag = 0, startBlock, len, j, k;
    char ch;
    printf("Enter the starting block and the length of the files: ");
    scanf("%d %d", &startBlock, &len);
    for (j=startBlock; j<(startBlock+len); j++){
        if (files[j] == 0)
            flag++;
    }
    if(len == flag){
        for (int k=startBlock; k<(startBlock+len); k++){
            if (files[k] == 0){
                files[k] = 1;
                printf("%d ", k);
            }
        }
        if (k != (startBlock+len-1))
            printf("\nThe file is allocated to the disk\n");
    }
    else
        printf("The file is not allocated to the disk\n");

    printf("Do you want to enter more files?\n");
    printf("Press y/n?: ");
    scanf(" %c", &ch);
    if (ch == 'y')
        recurse(files);
    else
        exit(0);
    return;
}

int main()
{
int files[500]={0};
for(int i=0;i<50;i++)
files[i]=0;
printf("Files Allocated are :\n");

recurse(files);
return 0;
}