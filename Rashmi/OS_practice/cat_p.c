#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc,char *argv[])
{
	int fd,nread,ret;
	char buff[100];
	fd=open(argv[1],O_RDONLY);
	if(fd < 0){
		perror("Open fails\n");
		exit(1);
	}
	nread=read(fd,buff,100);
	if(nread < 0){
		perror("Read fails\n");
		exit(1);
	}
	while(nread != 0){
		ret=write(1,buff,nread);
		if(ret < 0){
			perror("Write fails\n");
			exit(1);
		}
		nread=read(fd,buff,100);
	}
	close(fd);
	return 0;
}
