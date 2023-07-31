/******************************************************************************************** 
  WAP producer process and consumer process synchronization using named semaphores.
 *********************************************************************************************/

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
int a,b,n=0,m=0;
pid_t child_pid;
int shmid;


void terminate(int sig)
{
	printf("I got a signal for terminate, for terminate CTRL+C\n");
	sem_unlink("producer1");
	sem_unlink("consumer1");
	signal(SIGINT,SIG_DFL);
}

void main()
{
	
	signal(SIGINT,terminate);
	
	//creating shared mwmory
	
	shmid = shmget(55,1024,0666 | IPC_CREAT);
	if(shmid<0){
		perror("shared memory error : ");
		exit(1);
	}
	
	
	// attach
	
	
	
	
	prod_lock=sem_open("producer1",O_CREAT,0666,1);
	if(prod_lock==NULL)
	{
		perror("semaphore1");
		exit(0);
	}
	cons_lock=sem_open("consumer1",O_CREAT,0666,0);
	if(cons_lock==NULL)
	{
		perror("semaphore2");
		exit(1);
	}
	sem_getvalue(prod_lock,&a);
	sem_getvalue(cons_lock,&b);
	printf("prod:%d   cons:%d\n",a,b);

	child_pid=fork();
	
	if(child_pid==0)
	{
		sem_wait(cons_lock);

		if((shmid=shmget(55,1024,0))==-1) {
			perror("shmget");
			exit(1);
		}

		msg=shmat(shmid,0,0);
	
		printf("Data written in the shared memory is:%s\n",msg);

		getchar();
		sem_post(prod_lock);

	}
	else
	{
		sem_wait(prod_lock);
		msg=shmat(shmid,0,0);
		printf("Enter the data you want to write into shared memory\n");
		fgets(msg,1024,stdin);printf("Data successfully written\n");
		getchar();
		//shmdt(msg);
		sem_post(cons_lock);	

			
	}
	shmdt(msg);
	
}

