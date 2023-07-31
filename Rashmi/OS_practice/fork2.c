#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	char *message;
	int n,exit_code;

	printf("Start\n");
	pid=fork();

	switch(pid){
		case -1:
			perror("Fork fail\n");
			exit(1);

		case 0:
			message = "Child";
			printf("child PID= %d\n child PPID= %d\n",getpid(),getppid());
			n=5;
			exit_code =37;
			break;
		default:
			message = "Parent";
			printf("parentPID= %d\n parent PPID= %d\n",getpid(),getppid());
			n=3;
			exit_code=0;
			break;
	} 

	for(;n>0;n--){
		puts(message);
		sleep(1);
	}
		
	if (pid != 0) {
	int stat_val;
	pid_t child_pid;
	child_pid = wait(&stat_val); // stat_val: Upper Byte:Exit status; Lower Byte:Signal Number
	printf("Exit status: stat_val Upper Byte%d\n",stat_val>>8); // Print Exit status
	printf("Child has finished: PID = %d\n", child_pid);

	if(WIFEXITED(stat_val))
		printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
	else
	{
		printf("Child terminated abnormally\n");
	printf("Exit status: stat_val Lower Byte%d\n",stat_val); // Print Exit status
	}
}


	exit(exit_code);  //child will give the exit while terminating to parent because parent is in wait 
}
