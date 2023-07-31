#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <linux/input.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int i,rd,fd1,retfd,ledfd;
	char buf[4096];
	int val;
	char name[256] = "Unknown";
	struct input_event ev[64];
	fd1=open(argv[1],O_RDONLY);
	if(fd1<0)
		printf("error while open the file event1\n");
        ioctl(fd1, EVIOCGNAME(sizeof(name)), name);
        printf("Input device name: \"%s\"\n", name);

	ledfd = open("/sys/class/gpio/gpio10/value",O_RDWR);
	if(ledfd<0){
		perror("led value not oppened:");
		exit(1);
	}
	write(ledfd, "0",1);
	while(1)
	{
		rd=read(fd1, ev, sizeof(struct input_event) * 64);
        	if (rd < (int) sizeof(struct input_event)) {
                        printf("yyy\n");
                        perror("\nevtest: error reading");
                        return 1;
         	}
        	for (i = 0; i < rd / sizeof(struct input_event); i++){
			printf("Event: time %ld.%06ld, type %d , code %d , value %d\n",ev[i].time.tv_sec, ev[i].time.tv_usec, ev[i].type,ev[i].code, ev[i].value);
	
	
		if(ev[i].code == 115 ){
			write(ledfd, "1",1);
			
		}
		}
		
		}
	return 0;
}
