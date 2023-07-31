/*client*/
/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>


//void * client_thread(void * arg);
void * read_handler(void * arg);
void * write_handler(void * arg);

void *blink_handler(void * arg);

// signal handlers
void blink_on(int);
void blink_off(int);

int client_sockfd,red_fd;
static int blink_flag=0;
pthread_t read_thread, write_thread, blink_thread;

int main()
{
	//int client_sockfd;
	int client_len;
	struct sockaddr_in client_addr;
	int ret;

	void * ret_val;

/*  Create a socket for the client.  */

	client_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket, as agreed with the server.  */

	client_addr.sin_family = AF_INET;
    	client_addr.sin_addr.s_addr = inet_addr("192.168.76.224");
    	client_addr.sin_port = 9734;
    	client_len = sizeof(client_addr);

 	red_fd = open("/sys/class/gpio/gpio10/value",O_WRONLY);
/*  Now connect our socket to the server's socket.  */

	if(connect(client_sockfd, (struct sockaddr *)&client_addr, client_len) == -1)
	{
		perror("client connect fail:");
		exit(1);
	}

/*  create a thread.  */

	ret = pthread_create(&write_thread, NULL, write_handler, 0);
	if (ret != 0)
            {
                    perror("Read Thread creation failed");
                    exit(EXIT_FAILURE);
            }
	ret = pthread_create(&read_thread, NULL, read_handler, 0);
        if (ret != 0)
            {
                    perror("Read Thread creation failed");
                    exit(EXIT_FAILURE);
            }
	ret  = pthread_join(write_thread, &ret_val);
                if (ret != 0)
                {
                        perror("Thread join failed");
                        exit(EXIT_FAILURE);
                }
	ret  = pthread_join(read_thread, &ret_val);
                if (ret != 0)
                {
                        perror("Thread join failed");
                        exit(EXIT_FAILURE);
                }
	
	printf("Thread joined\n");

	close(client_sockfd);
	return 0;
}
void *read_handler(void *arg)
{
	int fd_1;
	char buff;
	while(1)
	{
		read(client_sockfd, &buff, 1);
		printf("From Server:\t\t%c\n",buff);
		if((buff=='R'))
		{
			printf("RED ON\n");
			//write(red_fd,"1",1);
			pthread_kill(blink_thread,SIGUSR1);
		
		}
		else if((buff == 'O'))
		{
			printf("RED OFF\n");
			//write(red_fd,"0",1);
			pthread_kill(blink_thread,SIGUSR2);
		}	
	}
	pthread_exit("Thank you");
}
void *write_handler(void *arg)
{
	int i,fd1,rd;
	char buff[1024];
	struct input_event ev[64];

	fd1=open("/dev/input/event0",O_RDONLY);
	if(fd1<0)
		printf("error while open the file event0\n");
	
	while(1)
	{
		i=0;
		while(1)
		{
			rd=read(fd1, ev, sizeof(struct input_event)*64);

			for (i = 0; i < rd / sizeof(struct input_event); i++)	
			{
				if(ev[i].code==115 && ev[i].value==1)
				{
					printf("UP\n");
					write(client_sockfd,"R", 1);
				}
				else if(ev[i].code==114 && ev[i].value==1)
				{
					printf("DOWN\n");
					write(client_sockfd,"O", 1);
				}
			}
		}
		//fgets(buff, 1024, stdin);
		//write(client_sockfd, buff, 1024);
//		sleep(1);
	}
	pthread_exit("Thank you");
}

void *blink_handler(void * arg)
{
	int red_fd;
	signal(SIGUSR1,blink_on);
	signal(SIGUSR2,blink_off);
	red_fd = open("/sys/class/gpio/gpio10/value",O_WRONLY);
	if(red_fd < 0){
		perror("open fail:");
		pthread_exit("read handler fail");
	}
	while(1)
	{
		pause();
		if(blink_flag == 1)
		{
	         	 write(red_fd,"1",1);
			 sleep(1);
       			 write(red_fd,"0",1);
			 sleep(1);
		}
		else
       			 write(red_fd,"0",1);
	}
	pthread_exit("Thank you");
}


/********   blink_on  Signal Handler  ***********/
void blink_on(int sig)
{
	blink_flag=1;        
}
/********   blink_off  Signal Handler  ***********/
void blink_off(int sig)
{
	blink_flag=0;        
}

