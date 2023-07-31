#include<stdio.h>
#include<errno.h>
#include<unistd.h>
int main()
{
	char buff[20];
	int nread;
	nread=read(0,buff,10);
	if(nread < 0){
		perror("Read fails: \n");
	}
	write(1,buff,nread);
	return 0;
}
