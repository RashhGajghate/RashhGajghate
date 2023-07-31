/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include<pthread.h>

void *tx(void *arg);
void *rx(void *arg);
char tra[50];
char rec[50];

int server_sockfd, client_sockfd;
int server_len, client_len;
struct sockaddr_in server_address;
struct sockaddr_in client_address;


int main()
{
    int res;
    pthread_t tx_thread,rx_thread;
    void *thread_result;

    
/*  Create an unnamed socket for the server.  */

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket.  */

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.76.224");
    server_address.sin_port = 9734;
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

/*  Create a connection queue and wait for clients.  */

    listen(server_sockfd, 5);
    while(1) {
        printf("server waiting for client\n");

/*  Accept a connection.  */

        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, 
            (struct sockaddr *)&client_address, &client_len);
            printf("Accepted the  client\n");

/*  We can now read/write to client on client_sockfd.  */
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
    }
    printf("Thread joined\n");
    exit(EXIT_SUCCESS);
    
    return 0;
}


void *tx(void *arg) {
    while(1)
	{
		fgets(tra,50,stdin);
		write(client_sockfd,tra,50);
		printf("Transmited string= %s",tra);
	}
	
   pthread_exit("exit");	
}
void *rx(void *arg) {
    while(1)
	{
		read(client_sockfd,rec,50);
		printf("Receive string= %s",rec);
	}
   pthread_exit("exit");	
}





