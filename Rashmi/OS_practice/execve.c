#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

char *const ps_argv[]={"ps","-eaf",0};

int main()
{
	int ret;
	printf("Start\n");   //Printing before the execve() system call

	getchar(); //For blocking system call we put keyboard input till we check the PID for process

	ret=execve("/bin/ps",ps_argv,NULL); //execve syntax

	if(ret < 0){
		perror("Execve fail: ");  //In case execve fails
		exit(0); //Then ex
	}

	printf("End\n");  //Printing after the execve() system call
	return 0;
}
