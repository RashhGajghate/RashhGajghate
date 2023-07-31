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

sem_t *prod_lock;
sem_t *cons_lock;

int main()
{

	int shmid;
	char *msg;
	prod_lock=sem_open("producer1",IPC_CREAT,0666,1);
	if(prod_lock==NULL)
	{
		perror("semaphore1");
		exit(0);
	}
	cons_lock=sem_open("consumer1",IPC_CREAT,0666,0);
	if(cons_lock==NULL)
	{
		perror("semaphore2");
		exit(1);
	}
																																																																																																																																																																																																							
	
	sem_wait(prod_lock);
	
	
	if((shmid=shmget(55,1024,0)==-1)) {
		perror("shmget");
		exit(1);
	}

	msg=shmat(shmid,0,0);
	
	printf("Data written in the shared memory is:%s\n",msg);

	sem_post(cons_lock);
	//getchar();
	//shmdt(msg);
	exit(1);
	return 0;
}
	
/**/	
