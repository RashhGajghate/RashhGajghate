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


void *producer(void *arg);

sem_t *prod;
sem_t *cons;
int shmid;
int main()
{
	pid_t pid,pid2;
	int res,rm,status;
	pthread_t one_thread,two_thread;
	void *thread_result;

	sem_unlink("s1");
	sem_unlink("s2");

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

	shmid=shmget(30,1024,0666 | IPC_CREAT);
	if(shmid == -1){
		perror("Shmget failed\n");
		exit(1);
	}


	pthread_create(&one_thread,NULL,producer,NULL);
	if(res != 0){
		perror("First thread creation failed\n");
		exit(EXIT_FAILURE);
	}

	pthread_join(one_thread,&thread_result);
	if(res != 0){
		perror("Thread join failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);

	rm=shmctl(shmid,IPC_RMID,0);
	if(rm < 0){
		perror("Shmctl fails\n");
		exit(1);
	}
	return 0;
}

void *producer(void *arg)
{
	char *msg;
	while(1){
		sem_wait(prod);
		msg=shmat(shmid,0,0);
		__fpurge(stdin);
		printf("Writting data to shared memory : ");
		fgets(msg,1024,stdin);
		shmdt(msg);
		sem_post(cons);
	}
}

