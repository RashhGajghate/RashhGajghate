/*server*/
/*  Make the necessary includes and set up the variables.  */

#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<linux/input.h>


//void *server_thread(void * arg);
void *read_handler(void * arg);
void *write_handler(void * arg);

int server_sockfd, client_sockfd,gpio_fd;

void terminate(int sig)
{
	printf("I got a signal for terminate, for terminate CTRL+C\n");
	close(client_sockfd);
	close(server_sockfd);
	signal(SIGINT,SIG_DFL);
}


int main()
{
	int server_len, client_len;
	struct sockaddr_in server_addr, client_addr;
	int ret;
	pthread_t write_thread, read_thread;
	void * ret_val;
	
	signal(SIGINT,terminate);
	
	
	// gpio file descriptor
	
	
/*  Create an unnamed socket for the server.  */
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_sockfd == -1)
	{
		perror("socket fails:");
		exit(EXIT_FAILURE);
	}

/*  Name the socket.  */
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("192.168.76.224");
	server_addr.sin_port = 9733;
	server_len = sizeof(server_addr);
	if(bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
	{
		perror("bind fail:");
		exit(EXIT_FAILURE);
	}

/*  Create a connection queue and wait for clients.  */
	
	if(listen(server_sockfd, 10) == -1)
	{
		perror("listen fail:");
                exit(EXIT_FAILURE);
	}

/*  Accept a connection.  */
	
	client_len = sizeof(client_addr);
	client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_len);

/* Create a thread. */

        ret = pthread_create(&read_thread, NULL, read_handler, 0);
        if (ret != 0)
        {
                perror("Read Thread creation failed");
                exit(EXIT_FAILURE);
        }
	ret = pthread_create(&write_thread, NULL, write_handler, 0);
        if (ret != 0)
        {
                perror("Write Thread creation failed");
                exit(EXIT_FAILURE);

        }

	ret  = pthread_join(read_thread, &ret_val);
	if (ret != 0)
	{
		perror("Thread join failed");         
    		exit(EXIT_FAILURE);
    	}
	ret  = pthread_join(write_thread, &ret_val);
        if (ret != 0)
        {
                perror("Thread join failed");         
                exit(EXIT_FAILURE);
        }
	
	printf("Thread joined\n");

	close(client_sockfd);
	return 0;
}


void *read_handler(void * arg)
{
	int ret;
	char buff[1024];
	gpio_fd = open("/sys/class/gpio/gpio10/value",O_WRONLY);
	if(gpio_fd < 0)
	{
		perror("gpio fd open failed : ");
		exit(1);
	}
	while(1)
	{
		ret = read(client_sockfd, buff, 1024);
		printf("buff = %s\n",buff);
		if(buff[0] == 'R'){
			printf("buff = %s\n",buff);
			write(gpio_fd,"1",1);
		}
		if(buff[0] == 'O'){
			printf("buff = %s\n",buff);
			write(gpio_fd,"0",1);		
		}
		//else
		//	continue;
		//printf("read ret:%d\n",ret);
		//if (ret == 0)
		//break;
		//printf("Consumer:%s\n",buff);
	}
	pthread_exit("Thank you");
}
void *write_handler(void * arg)
{
	char ch,buff[1024];
	while(1)
	{
		
		
		int i,fd1,rd;
		char buff[1024];
		struct input_event ev[64];

		fd1=open("/dev/input/event0",O_RDONLY);
		if(fd1<0)
		printf("error while open the file event0\n");
		
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
		
	}
	pthread_exit("Thank you");

}
