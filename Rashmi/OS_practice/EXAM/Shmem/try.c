#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

  
int main()
{
    // ftok to generate unique key
    //key_t key = ftok("shmfile",65);
  
    // shmget returns an identifier in shmid
    int shmid = shmget(20,1024,0666|IPC_CREAT);
  
    // shmat to attach to shared memory
    char *str = (char*) shmat(shmid,(void*)0,0);
  
    printf("Write Data : ");
    gets(str);
  
    printf("Data written in memory: %s\n",str);
      
    //detach from shared memory 

    getchar(); 
    shmdt(str);
    return 0;
}
