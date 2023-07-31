#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
	pid_t pid1,pid2,pid3;
	int status, exit_code=0;
	pid1=fork();  //Creating a duplicate process of parent using fork() syscall
	if(pid1 < 0){
		perror("Fork 1 failed\n");   //Error handling for fork()
		exit(1);
	}
	else if(pid1 == 0){
		printf("Child 1 process\n");
		printf("PPID : %d\n PID : %d\n",getppid(),getpid());  //APIs for getting PPID and PID child 1

		pid2 = fork();   //Creating a duplicate process of 1st child using fork() syscall
		if(pid2 < 0){
			perror("Fork 2 failed\n");   //Error handling for fork()
			exit(1);
		}
		else if(pid2 == 0){
			printf("Child 2 process\n");
			printf("PPID : %d\n PID : %d\n",getppid(),getpid());  //APIs for getting PPID and PID child 2

			pid3 = fork();  //Creating a duplicate process of 2nd child using fork() syscall
			if(pid3 < 0){
                       		perror("Fork 3 failed\n");  //Error handling for fork()
                        	exit(1);
               		 }
                	else if(pid3 == 0){
                        	printf("Child 3 process\n");
				printf("PPID : %d\n PID : %d\n",getppid(),getpid());  //APIs for getting PPID and PID child 3
				exit(exit_code);  //Exit status of child 3
			}
			else{
				wait(&status);  //Waiting for child 3 to terminate
			}
			
			exit(exit_code);  //Exit status of child 2
		}
		else{
			wait(&status);   //Waiting for child 2 to terminate
		}
		exit(exit_code);  //Exit status of child 1
 	}
	else{
		printf("Parent process\n");
		printf("PPID : %d\n PID :%d\n",getppid(),getpid());   //APIs for getting PPID and PID for parent
		wait(&status);    //Waiting for child 1 to terminate
	}
	return 0;
}
