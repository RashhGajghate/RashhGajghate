#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


int   main()
{
	int fd,fd1;
	char s_buff[2];
	
	
	fd=open("/sys/class/gpio/gpio10/value",O_WRONLY);
	if(fd < 0)
	{
		perror("Open fail");
	}

	fd1=open("/sys/class/gpio/gpio26/value:",O_RDONLY);
	if(fd1 < 0)
	{
		perror("Open fail");
	}
	while(1){
		read(fd1,s_buff,1);
		if(s_buff[0] == 1)
		{
			printf("1");
			write(fd,"1",1);
			sleep(1);
		}
		else
		{	printf("0");
			write(fd,"0",1);
			sleep(1);
		}
		}

	return 0;
	}
