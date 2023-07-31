#include <stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>

int main()
{
	int shmid;
	char *msg;
	
	if((shmid=shmget(15,1024,666|IPC_CREAT|IPC_EXCL))==-1) {
		perror("shmget");
		exit(1);
	}
	
	msg=shmat(shmid,0,0);
	
	printf("Enter the data you want to write into shared memory\n");
	fgets(msg,1024,stdin);
	
	printf("Data successfully written\n");
	
	//getchar();
	shmdt(msg);
	return 0;
}
	
	
