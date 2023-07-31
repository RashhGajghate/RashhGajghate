#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char msg[] = "Hello World";
void *thread_fun(void *arg);

int main()
{
	int ret;
	int ret1;
	pthread_t even;
	pthread_t odd;
	void *retval;

	ret = pthread_create(&even,NULL,thread_fun,(void *)msg);
	if (ret < 0){
		perror("pthread create fail:");
		exit(0);
	}

	ret = pthread_create(&odd,NULL,thread_fun1,(void *)msg);
        if (ret1 < 0){
                perror("pthread create fail:");
                exit(0);
        }


	ret = pthread_join(even,&retval);
	if (ret < 0){
		perror("pthread join fail:");
		exit(0);
	}
	printf("retval from new thread1:%s\n",(char *)retval);
	

	return 0;
}

void *thread_fun(void *arg)
{	int i=0;
	for(i=0;i<=100;i++){
		if(i%2 == 0){
			printf("Even= %d\n",i);
		}
	}
	if(i == 100){
		pthread_exit("Done\n");	
	}
}




