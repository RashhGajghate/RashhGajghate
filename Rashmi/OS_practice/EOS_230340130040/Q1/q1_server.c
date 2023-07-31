#include<stdio.h>
#include <stdio_ext.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>        
#include<sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<signal.h>

//Handler declarations
void *write_handler(void *arg);
void *read_handler(void *arg);

int client_fd;
int server_fd;

void terminate(int sig)
{
	printf("I got a signal for terminate, for terminate CTRL+C\n");
	close(client_fd);  //closing file descriptor
	close(server_fd);  //closing file descriptor
	signal(SIGINT,SIG_DFL);
}
int main()
{
	pthread_t write_thread, read_thread;
	void **write_retval;
	void **read_retval;
	int ret, server_len, client_len;
	struct sockaddr_in server_addr, client_addr;
	
	signal(SIGINT,terminate);
	server_fd = socket(AF_INET, SOCK_STREAM, 0);  //Creating socket and getting a file descriptor
	if(server_fd == -1){
		perror("Socket creation failed\n"); 
		exit(1);
	}
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = 9001;
	server_len = sizeof(server_addr);
	ret = bind(server_fd, (struct sockaddr *)&server_addr, server_len);  //Binding socket
	if(ret == -1){
		perror("Bind failed\n");
		exit(1);
	}

	ret = listen(server_fd,10);   //Listening for connection on socket
	if(ret == -1){
                perror("Listen failed\n");
                exit(1);
        }
	
	client_len = sizeof(client_addr);
	client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len); //For accepting a connection on socket as well as getting another FD
	if(ret == -1){
                perror("Accpet failed\n");
                exit(1);
        }

	//Thread creation for read and write
	ret = pthread_create(&write_thread, NULL, write_handler, NULL);
	if(ret != 0){
		perror("Write thread failed\n");    //error handling for pthread_create
		exit(EXIT_FAILURE);
	}
	
	ret = pthread_create(&read_thread, NULL, read_handler, NULL);
        if(ret != 0){
                perror("Read thread failed\n");   //error handling for pthread_create
                exit(EXIT_FAILURE);
        }

	//Thread joing for read and write
	ret = pthread_join(write_thread, write_retval);
	if(ret != 0){
                perror("Write join failed\n");   //error handling for pthread_join
                exit(EXIT_FAILURE);
        }

	ret = pthread_join(read_thread, read_retval);
        if(ret != 0){
                perror("Read join failed\n");   //error handling for pthread_join
                exit(EXIT_FAILURE);
        }
	printf("Thread join successfully\n");
	return 0;
}

void *write_handler(void *arg)  //read thread handle
{
	char write_buff[1024];
	int ret;
	while(1){
		__fpurge(stdin);
		fgets(write_buff, 1024, stdin);
		ret = write(client_fd, write_buff, 1024);  
		if(ret < 0){
			printf("Write failed\n");  //error handling for write() syscall
			exit(1);
		}
	}
	pthread_exit("Done\n");
}

void *read_handler(void *arg)  //read thread handle
{
	char read_buff[1024];
	int ret;
	while(1){
		ret = read(client_fd, read_buff, 1024);
		if(ret < 0){
                        printf("Write failed\n");  //error handling for read() syscall
                        exit(1);
                }
          printf("Reading data from client : %s\n",read_buff);
	}
	pthread_exit("Done\n");
}




