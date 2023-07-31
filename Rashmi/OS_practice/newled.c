#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>



int main()
{
	int sw1_fd,sw2_fd,ld2_fd,ld1_fd;
	char arr1 = '\0';
	char arr2 = '\0';


	ld1_fd = open("/sys/class/gpio/gpio10/value",O_WRONLY);
	if(ld1_fd<0){
		perror("file descripter error : ");
		exit(1);
	}



	ld2_fd = open("/sys/class/gpio/gpio9/value",O_WRONLY);
	if(sw1_fd<0){
		perror("file descripter error : ");
		exit(1);
	}



	while(1){
		sw1_fd = open("/sys/class/gpio/gpio26/value",O_RDONLY);
		if(sw1_fd<0){
			perror("file descripter error : ");
			exit(1);
		}
		
		sw2_fd = open("/sys/class/gpio/gpio27/value",O_RDONLY);
		if(sw2_fd<0){
			perror("file descripter error : ");
			exit(1);
		}
		
		
		
		read(sw1_fd,&arr1,1);
		
		
		printf("value of gpio 26 : %c\n",arr1);
		if(arr1 == '1'){
			write(ld1_fd,"1",1);
			sleep(1);
		}
		else{
			write(ld1_fd,"0",1);
			sleep(1);
		}
		
		read(sw2_fd,&arr2,1);
		
		printf("value of gpio 27 : %c\n",arr2);
		if(arr2 == '1'){
			write(ld2_fd,"1",1);
			sleep(1);
		}
		else
		{
			write(ld2_fd,"0",1);
			sleep(1);
		}

		
	}
	
}
