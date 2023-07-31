/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


void *tx(void *arg);
void *rx(void *arg);
char tra[50];
char rec[50];
int sockfd;
struct sockaddr_in address;

int main()
{
    
    int len;
    int result;
    int res;
    
     pthread_t tx_thread,rx_thread;
    void *thread_result;

/*  Create a socket for the client.  */

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket, as agreed with the server.  */

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("192.168.40.237");
    address.sin_port = 9734;
    len = sizeof(address);

/*  Now connect our socket to the server's socket.  */

    result = connect(sockfd, (struct sockaddr *)&address, len);

    if(result == -1) {
        perror("oops: client2");
        exit(1);
    }

	res = pthread_create(&tx_thread, NULL, tx, NULL);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }

    res = pthread_create(&rx_thread, NULL, rx, NULL);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
   // printf("Wait for pthread_join\n");
    res = pthread_join(tx_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_join(rx_thread, &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined\n");
    exit(EXIT_SUCCESS);

/*  We can now read/write via sockfd.  */
  
   exit(0);
}

void *tx(void *arg) {
    while(1)
	{
		fgets(tra,50,stdin);
		write(sockfd,tra,50);
		printf("Transmited string= %s\n",tra);
	}
	
   pthread_exit("exit");	
}
void *rx(void *arg) {
    while(1)
	{
		read(sockfd,rec,50);
		printf("Receive string= %s\n",rec);
	}
   pthread_exit("exit");	
}















