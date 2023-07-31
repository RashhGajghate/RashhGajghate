
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main()
{
	int fd,ret;

	fd = open("/home/desd/abc",O_RDWR | O_CREAT);
	if(fd < 0){
		perror("open fail:");
		return -1;
	}

	ret =	write(fd,"Hello World\n",12);
//	printf("ret:%d\n",ret);
//	printf("errno:%d\n",errno);
	if(ret < 0){
		perror("write fail:");
	}
	close(fd);
	return 0;
}
