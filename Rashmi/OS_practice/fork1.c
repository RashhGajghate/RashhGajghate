#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//just getting pid and ppid of child and parent

int main()
{
	pid_t pid;
	getchar();
	pid = fork();
	if(pid == -1)
		perror("Fork fails\n");

	if(pid == 0){
		sleep(20);
		printf("Child process PID= %d\n",getpid());
		printf("Child process PPID= %d\n",getppid());
		//exit(0);  //whenever child terminates it will give exit(0)
	}
	else{
		sleep(20);
		printf("Parent process PID= %d\n",getpid());
		printf("Parent process PPID= %d\n",getppid());
		//exit(0); //when parent terminates it will give exit(0)
	}
	return 0;
}
