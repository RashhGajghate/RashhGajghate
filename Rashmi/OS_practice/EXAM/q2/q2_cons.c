#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio_ext.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>



void *consumer(void *arg);

sem_t *prod;
sem_t *cons;
int shmid;
int main()
{
	pid_t pid,pid2;
	int res,rm,status;
	pthread_t two_thread;
	void *thread_result;

	prod = sem_open("s1", O_CREAT, 0666, 1);
	if(prod == SEM_FAILED){
		perror("s1 failed\n");
		exit(0);
	}

	cons = sem_open("s2", O_CREAT, 0666, 0);
	if(cons == SEM_FAILED){
		perror("s2 failed\n");
		exit(0);
	}

	shmid=shmget(30,1024,0);
	if(shmid == -1){
		perror("Shmget failed\n");
		exit(1);
	}
	
	pthread_create(&two_thread,NULL,consumer,NULL);
	if(res != 0){
		perror("First thread creation failed\n");
		exit(EXIT_FAILURE);
	}

	pthread_join(two_thread,&thread_result);
	if(res != 0){
		perror("Thread join failed\n");
		exit(EXIT_FAILURE);
	}

	rm=shmctl(shmid,IPC_RMID,0);
	if(rm < 0){
		perror("Shmctl fails\n");
		exit(1);
	}
	return 0;
}

void *consumer(void *arg)
{
	char *msg;
	while(1){
		sem_wait(cons);
		msg=shmat(shmid,0,0);
		printf("Reading data to shared memory : %s\n",msg);
		shmdt(msg);
		sem_post(prod);
	}
}



