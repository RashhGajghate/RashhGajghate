#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc,char *argv[])
{
	int fd,nread,fd1;
	char buff[100];
	fd=open(argv[1],O_RDONLY);
	fd1=open(argv[2],O_WRONLY | O_CREAT);
	if(fd < 0){
		perror("open fail: \n");
	}
	printf("fd= %d\n",fd);
	printf("fd1= %d\n",fd1);
	nread=read(fd,buff,100);
	if(nread < 0){
		perror("read fail: \n");
	}
	while(0 != nread){
		write(fd1,buff,nread);
		nread=read(fd,buff,100);
	}
	close(fd); 
	close(fd1);
	return 0;
}
