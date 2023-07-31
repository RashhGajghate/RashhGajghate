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
char *msg;
pid_t child_pid;
int shmid,a,b;
//char *argv[]= {"cons"};

void terminate(int sig)
{
	printf("I got a signal for terminate, for terminate CTRL+C\n");
	sem_unlink("producer1");
	sem_unlink("consumer1");
	signal(SIGINT,SIG_DFL);
}

int main()
{
	int ret,status;
	signal(SIGINT,terminate);

	shmid = shmget(55,1024,0666 | IPC_CREAT);
	
	
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
	
	child_pid = fork();
	
	if (child_pid == 0)
	{
		ret = execl("consumer","consumer",NULL);
		if(ret<0){
			perror("execve fails");
			exit(1);
		}
	}
	else
	{
		sem_wait(prod_lock);
		
		if(shmid<0){
		perror("shared memory error : ");
		exit(1);
	            }
	
	        msg=shmat(shmid,0,0);
	        
		printf("Enter the data you want to write into shared memory\n");
		fgets(msg,1024,stdin);
		printf("Data successfully written\n");
		getchar();
		sem_post(cons_lock);
		///wait(&status);
		
	}
		shmdt(msg);
	
	
	return 0;
}

