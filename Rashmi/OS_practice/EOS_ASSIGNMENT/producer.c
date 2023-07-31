#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/mman.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>


sem_t *prod_lock,*cons_lock;
char *msg;
int a,b,shmid;
pid_t child_pid;

void terminate(int sig)
{
	printf("I got a signal for terminate, for terminate CTRL+C\n");
	sem_unlink("producer1");
	sem_unlink("consumer1");
	signal(SIGINT,SIG_DFL);
}
int main()
{
	signal(SIGINT,terminate);
	shmid = shmget(55,1024,0666 | IPC_CREAT);
	if(shmid<0){
		perror("shared memory error : ");
		exit(1);
	}
	
	msg = shmat(shmid,0,0);
	
	prod_lock = sem_open("producer1",O_CREAT,0666,1);
	if(prod_lock == NULL){
		perror("semaphore1");
		exit(1);
	}

	cons_lock = sem_open("consumer1",O_CREAT,0666,0);
	if(prod_lock == NULL){
		perror("semaphore2");
		exit(1);
	}
	
	child_pid = fork();
	
	if(child_pid == 0){
		sem_wait(cons_lock);
		execl("/bin/sh","/consumer")
	}
		
	

}
