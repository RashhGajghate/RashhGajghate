#include<stdio.h>
ssize_t read(int fd,void *buf,size_t count);
ssize_t write(int fd,const void *buf,size_t count);

int main()
{
	char buf[30];
	int size;
	size=read(0,buf,10);
	write(1,buf,size);
}
