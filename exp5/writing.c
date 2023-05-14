#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

void main(){
	key_t key= ftok("shmfile",43);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	printf("Identifier for shared memory: %d\n",shmid);
	void * shared_memory= shmat(shmid,NULL,0);
	printf("Process attached is %p \n",shared_memory);
	printf("Enter data to write to shared memory: ");
	char buff[100];
	scanf("%s",buff);
	strcpy(shared_memory,buff);
	printf("Data written to shared memory is: %s \n",(char*)shared_memory);
	shmdt(shared_memory);
}