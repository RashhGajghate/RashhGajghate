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
void *consumer(void *arg);
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

	shmid=shmget(50,1024,0666 | IPC_CREAT | 0666);
	if(shmid == -1){
		perror("Shmget failed\n");
		exit(1);
	}


	pid = fork();
	if(pid < 0){
		perror("Fork failed\n");
		exit(1);
	}
	else if(pid == 0){
		printf("Child 1 process\n");
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
	}
	else{
		printf("Parent process\n");
		pid2 = fork();
		if(pid2 < 0){
			perror("Fork failed\n");
			exit(1);
		}
		else if(pid2 == 0){
			printf("Child 2 process\n");
			pthread_create(&two_thread,NULL,consumer,NULL);
			if(res != 0){
				perror("Second thread creation failed\n");
				exit(EXIT_FAILURE);
			}

			pthread_join(two_thread,&thread_result);
			if(res != 0){
				perror("Thread join failed\n");
				exit(EXIT_FAILURE);
			}
		}
		else{
			printf("Parent process after creaction of child 1\n");
			waitpid(pid, &status, 0);
			printf("Parent process after creation of child 2\n");
			waitpid(pid2, &status, 0);
		}
	}

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
		printf("Writting data : ");
		fgets(msg,1024,stdin);
		shmdt(msg);
		sem_post(cons);
	}
}

void *consumer(void *arg)
{
	char *msg;
	while(1){
		sem_wait(cons);
		msg=shmat(shmid,0,0);
		printf("Reading data : %s\n",msg);
		shmdt(msg);
		sem_post(prod);
	}
}



