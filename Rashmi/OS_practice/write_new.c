#include<stdio.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	int ret;
	ret=write(3,"Rashmi Gajghate\n",20);
	if(ret < 0){
		perror("Write fail: ");
	}
	printf("Errno: %d\n",errno);
	return 0;
}
