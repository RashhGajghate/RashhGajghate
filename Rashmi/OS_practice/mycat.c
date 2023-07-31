#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc,char *argv[])
{
	char buff[100];
	int nread,fd;

	fd=open(argv[1],O_RDWR);
	printf("fd= %d\n",fd);
	if(fd<0){
		perror("Open error: \n");
	}

	nread=read(fd,buff,100);
	if(nread<0){
		perror("Read error: \n");
	}

	while(0 != nread){
		write(1,buff,nread);
		nread=read(fd,buff,100);
	}
	close(fd);
	return 0;

}

