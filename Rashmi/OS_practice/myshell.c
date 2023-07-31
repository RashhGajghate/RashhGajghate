#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
#include<string.h>
int main()
{
	pid_t pid;
	char buff[20];
	int ret,status;
	printf("Enter command: ");
//	scanf("%[^\n]s",buff);
	gets(buff);
	pid = fork();
	if (pid == 0)
	{
		ret = execl("/bin/sh", "sh", "-c", buff, NULL);
		if(ret == -1)
			perror("execve fails");
		exit(0);
	}
	else
	{
		wait(&status);
	}
	return 0;
}

