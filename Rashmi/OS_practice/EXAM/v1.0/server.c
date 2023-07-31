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
#include <sys/ipc.h>
#include <sys/shm.h>
//void *server_thread(void * arg);
//void *read_handler(void * arg);
void *write_handler(void * arg);

int server_sockfd, client_sockfd;

int main()
{
	//int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_addr, client_addr;
	int ret;
	pthread_t write_thread;
	void * ret_val;

/*  Create an unnamed socket for the server.  */
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_sockfd == -1)
	{
		perror("socket fails:");
		exit(EXIT_FAILURE);
	}

/*  Name the socket.  */
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = 9734;
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

	 int shmid = shmget(20,1024,0666|IPC_CREAT);
	  // shmat to attach to shared memory

	   ret = pthread_create(&write_thread, NULL, write_handler, 0);
        if (ret != 0)
        {
                perror("Write Thread creation failed");
                exit(EXIT_FAILURE);

        }
        printf("Thread created successfully\n");
        
	   ret  = pthread_join(write_thread, &ret_val);
        if (ret != 0)
        {
                perror("Thread join failed");         
                exit(EXIT_FAILURE);
        }
        printf("Thread joined\n");
      //shmdt(str);  //detach from shared memory
	printf("Memory detached\n");
	close(client_sockfd);
	return 0;
}


void *write_handler(void * arg)
{
    char *str = (char*) shmat(shmid,(void*)0,0); 
    printf("Write Data : ");
    gets(str);
    printf("Data written in memory: %s\n",str); 
    getchar();
    pthread_exit("Thank you");
}


