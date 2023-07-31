#include<stdio.h>
#include <stdio_ext.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>        
#include<sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//Thread handlers
void *write_handler(void *arg);
void *read_handler(void *arg);
int client_fd;
int main()
{
	pthread_t write_thread, read_thread;
	void **write_retval;
	void **read_retval;
	int ret, client_len;
	struct sockaddr_in client_addr;
	
	client_fd = socket(AF_INET, SOCK_STREAM, 0);  //Creating socket and getting a file descriptor
	if(client_fd == -1){
		perror("Socket creation failed\n");
		exit(1);
	}
	
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	client_addr.sin_port = 9001;
	client_len = sizeof(client_addr);
	ret = connect(client_fd,( struct sockaddr *)&client_addr, client_len);
	if(ret != 0){
		perror("Connect failed\n");
		exit(1);
	}

     //Thread creation for read and write thread
	ret = pthread_create(&write_thread, NULL, write_handler, NULL);
	if(ret != 0){
		perror("Write thread failed\n");   //error handling for pthread_create
		exit(EXIT_FAILURE);
	}
	
	ret = pthread_create(&read_thread, NULL, read_handler, NULL);
        if(ret != 0){
                perror("Read thread failed\n");  //error handling for pthread_create
                exit(EXIT_FAILURE);
        }

	//Thread joining, for joining with terminated thread
	ret = pthread_join(write_thread, write_retval);
	if(ret != 0){
                perror("Write join failed\n");   //error handling for pthread_join
                exit(EXIT_FAILURE);
        }

	ret = pthread_join(read_thread, read_retval);  
        if(ret != 0){
                perror("Read join failed\n");  //error handling for pthread_join
                exit(EXIT_FAILURE);
        }
	printf("Thread join successfully\n");
	
	close(client_fd); //closing file descriptor
	return 0;
}

void *write_handler(void *arg)   //write thread handler
{
	char write_buff[1024];
	int ret;
	while(1){
		__fpurge(stdin);
		fgets(write_buff, 1024, stdin);  //taking data from user
		ret = write(client_fd, write_buff, 1024);  //writing data to buffer
		if(ret < 0){     
			printf("Write failed\n");  //error handling for write() syscall
			exit(1);
		}
	}
	pthread_exit("Done\n");
}

void *read_handler(void *arg)  //read thread handler
{
	char read_buff[1024];
	int ret;
	while(1){
		ret = read(client_fd, read_buff, 1024);  //Read syscall for reading data
		if(ret < 0){
                        printf("Read failed\n");  //error handling for read() syscall
                        exit(1);
                }
          printf("Reading data from server : %s\n",read_buff);
	}
	pthread_exit("Done\n");
}




