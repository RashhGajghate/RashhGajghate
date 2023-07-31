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
#include <sys/ipc.h>
#include <sys/shm.h>
//void * client_thread(void * arg);
void * read_handler(void * arg,char *str);
//void * write_handler(void * arg);
int client_sockfd;

int main()
{
	//int client_sockfd;
	int client_len;
	struct sockaddr_in client_addr;
	int ret;
	pthread_t read_thread;
	void * ret_val;

/*  Create a socket for the client.  */

	client_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket, as agreed with the server.  */

	client_addr.sin_family = AF_INET;
    	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    	client_addr.sin_port = 9734;
    	client_len = sizeof(client_addr);

/*  Now connect our socket to the server's socket.  */

	if(connect(client_sockfd, (struct sockaddr *)&client_addr, client_len) == -1)
	{
		perror("client connect fail:");
		exit(1);
	}

/*  create a thread.  */

            ret = pthread_create(&read_thread, NULL, read_handler, 0);
        if (ret != 0)
            {
                    perror("Read Thread creation failed");
                    exit(EXIT_FAILURE);
            }
           int shmid = shmget(20,1024,0666);   // shmget returns an identifier in shmid
           char *str = (char*) shmat(shmid,(void*)0,0);  // shmat to attach to shared memory
           
	ret  = pthread_join(read_thread, &ret_val);
                if (ret != 0)
                {
                        perror("Thread join failed");
                        exit(EXIT_FAILURE);
                }
	shmdt(str);  //detach from shared memory 
     shmctl(shmid,IPC_RMID,NULL);  // destroy the shared memory
	printf("Thread joined\n");
	close(client_sockfd);
	return 0;
}
void *read_handler(void *arg,char *str)
{
	//char *str[1024];
    // ftok to generate unique key
    //key_t key = ftok("shmfile",65);
    printf("Data read from memory: %s\n",str);
    pthread_exit("Thank you");
}


