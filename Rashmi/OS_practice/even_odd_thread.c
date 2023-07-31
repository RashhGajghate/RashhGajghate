#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int num=0;
char msg[]="0";
void *thread_fun(void *arg);
//void *thread_fun1(void *arg);
int main()
{
	int ret;
	pthread_t even;
	//pthread_t odd;
	void *retval;
	//void *retval1;

	ret = pthread_create(&even,NULL,thread_fun,(void *)msg);
	if (ret < 0){
		perror("pthread create fail:");
		exit(0);
	}
	ret = pthread_join(even,&retval);
	if (ret < 0){
		perror("pthread join fail:");
		exit(0);
	}
	printf("retval from new thread:%s\n",(char *)retval);

	return 0;
}

// thread handler
void *thread_fun(void *arg)
{
	for(int i=0;i<100;i++){
	if(num%2 == 0){
		printf("Even thread= %d\n",num);
		num++;
	}
			       }	     
	if(num == 100){		
		pthread_exit("Done");
	}	
}


