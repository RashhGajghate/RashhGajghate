#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>

int main()
{
	int ret,status;
	pid_t pid;
	char *argv[]={"ps","-eaf",0};
	pid=fork();
	
	if(pid == 0){

	}
	else{
		
		ret=execve("/bin/ps",argv,NULL);
		if(ret == -1){
			perror("execve error\n");
			exit(0);
		}
		//wait(&status);
	}

	return 0;

}
