#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<errno.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio_ext.h>
#include<semaphore.h>

//sem_t lock_p,lock_c;
sem_t *sem_empty, *sem_full;

int shmid;
void* shm_Producer()
{
char *msg;

	while(1)
	{
		printf("prod begin:%d\n",shmid);
		sem_wait(sem_empty); //--------------------------------------------


		msg=(char *)shmat(shmid,0,0);

		printf("working1\n");
		//__fpurge(stdin);
		printf("Enter the data you want to write into shared memory or 'e' for exiting:\n");

		//msg='A';
		fgets(msg,1024,stdin);
		//scanf("%[^\n]s",msg);
		printf("%s\n",msg);
		if(!strcmp(msg,"e"))
		{
			if(shmctl(shmid,IPC_RMID,0)==-1) 
			{
				perror("shmctl");
				exit(1);
			}
			printf("\nShared memory successfully removed\n");
			pthread_exit(NULL);
		}
		printf("Data successfully written\n");
		shmdt(msg);	
		sem_post(sem_full);//-------------------------------------------
	}

}

void* shm_Consumer()
{
char *msg;

	while(1)
	{
		printf("cons begin:%d\n",shmid);
		sem_wait(sem_full);	//-------------------------------------------
		msg=shmat(shmid,0,0);

		printf("Data written in the shared memory is:%s\n",msg);

		shmdt(msg);

		sem_post(sem_empty);	//-----------------------------------------------
	}		

}

int main()
{
	pid_t pid1,pid2;

	sem_unlink("s2");
	sem_unlink("s3");
	sem_empty=sem_open("s2",O_CREAT,O_RDWR,1);
        sem_full=sem_open("s3",O_CREAT,O_RDWR,0);
       if(sem_empty==SEM_FAILED)
         {
                perror("sem_empty failed:");
                exit(0);
        }

        if(sem_full==SEM_FAILED)
        {
                 perror("sem_full failed:");
                exit(0);
        }

		if((shmid=shmget(24,1024,IPC_CREAT|0666))==-1) 	
		{		
			perror("shmget");
			exit(1);
		}



 	pid1=fork();
	int status;
	//sem_init(&lock_p,2,1);
	//sem_init(&lock_c,2,0);



	if(pid1<0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if(pid1==0)
	{

		pthread_t th1;
		printf("child 1 created and its pid is : %d\n",getpid());
		printf("Child 1's parent's pid : %d\n",getppid());
		if(pthread_create(&th1,NULL,&shm_Producer,NULL)!=0)
		{
			perror("pthread_create error in child 1");
			exit(1);
		}
		if(pthread_join(th1,NULL)!=0)
		{
			perror("failed to join thread 1");
			exit(1);
		}
	}
	else 
	{	
		pid2=fork();
		if(pid2<0)
		{
			perror("Fork failed");
			exit(1);
		}
		else if(pid2==0)
		{
	
			pthread_t th2;
			printf("child 2 created and its pid is : %d\n",getpid());
			printf("Child 2's parent's pid : %d\n",getppid());
			if(pthread_create(&th2,NULL,&shm_Consumer,NULL)!=0)
			{
				perror("pthread_create error in child 2");
				exit(1);
			}
			if(pthread_join(th2,NULL)!=0)
			{
				perror("failed to join thread 2");
				exit(1);
			}
		
		}
		else 
		{	
			printf("In parent process after creating child 1\n");
			waitpid(pid1,&status,0);
			printf("In parent process after creating child 2\n");
			waitpid(pid2,&status,0);
		
		}	
	}
}
