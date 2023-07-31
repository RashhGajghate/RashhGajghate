#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<semaphore.h>

sem_t ev, od;
char msg[] = "Hello World";
void *even_thread(void *arg);
void *odd_thread(void *arg);

//int flag=1,n;
// main thread
int main()
{
	int ret;
	pthread_t even,odd;
	void *retval;
	sem_init(&ev,0,1);
	sem_init(&od,0,0);
	ret = pthread_create(&even,NULL,even_thread,(void *)msg);
	if (ret < 0){
		perror("pthread create fail:");
		exit(0);
	}
	ret = pthread_create(&odd,NULL,odd_thread,(void *)msg);
	if (ret < 0){
		perror("pthread create fail:");
		exit(0);
	}
	ret = pthread_join(even,&retval);
	if (ret < 0){
		perror("pthread join fail:");
		exit(0);
	}
	ret = pthread_join(odd,&retval);
	if (ret < 0){
		perror("pthread join fail:");
		exit(0);
	}
	printf("retval from new thread:%s\n",(char *)retval);
	/*while(1)
	{
		printf("main thread\n");
	}*/	
	return 0;
}

// thread handler
void *even_thread(void *arg)
{
	int n=0;
	//printf("msg:%s\n",(char *)arg);
	

	while(n<=100)
	{
		
		sem_wait(&ev);
  		if(n%2 == 0)
		{
			printf("even:%d\n",n);
		}
		n++;
		
		sem_post(&od);
	}



//	sleep(5);
	pthread_exit("Thanks for CPU utilizing time cycles");	
}

void *odd_thread(void *arg)
{
	int n=0;
	//printf("msg:%s\n",(char *)arg);
	

	while(n<=100)
	{
		
		sem_wait(&od);
  		if(n%2 == 1)
		{ 
		printf("odd :%d\n",n);
		}
		n++;
		sem_post(&ev);
	}
	


//	sleep(5);
	pthread_exit("Thanks for CPU utilizing time cycles");	
}
