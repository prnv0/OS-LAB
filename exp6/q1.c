#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t chopsticks[5];
void* philosopher(void* n)
{
int i=*(int*)n;
sem_wait(&chopsticks[i]); //wait
printf("philosopher %d picks up left chopstick\n",i+1);
sem_wait(&chopsticks[(i+1)%5]);
printf("philosopher %d picks up right chopstick\n",i+1);
printf("philosopher %d is eating\n",i+1);
sleep(1);
printf("philosopher %d has finished eating\n",i+1);
sem_post(&chopsticks[(i+1)%5]);
//signal
printf("philosopher %d puts down right chopstick\n",i+1);
sem_post(&chopsticks[i]);
printf("philosopher %d puts down left chopstick\n",i+1);
printf("philosopher %d is thinking\n",i+1);
}
void main()
{
printf("no. of philosophers:5\n");
int arg[5];
pthread_t t[5];
for(int i=0;i<5;i++)
{
sem_init(&chopsticks[i],0,1);
}
for(int i=0;i<5;i++)
{ arg[i]=i;
pthread_create(&t[i],NULL,philosopher,(void*)&arg[i]);
}
for(int i=0;i<5;i++)
pthread_join(t[i],NULL);
}