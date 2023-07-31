#include<stdio.h>
#include<unistd.h>
#include<errno.h>


int main()
{
	int ret;
	ret=write(1,"Rashmi#include<stdio.h>
#include<unistd.h>
#include<errno.h>


int main()
{
	int ret;
	ret=write(1,"Rashmi\n",7);
	printf("Ret= %d\n",ret);
	printf("Errno: %d\n",errno);
	if(ret<0){
		perror("Write error: \n");
	}
	return 0;
}
