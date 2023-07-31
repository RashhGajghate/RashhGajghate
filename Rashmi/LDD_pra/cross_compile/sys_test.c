#include <stdio.h> 
#include <linux/kernel.h> 
#include <sys/syscall.h> 
#include <unistd.h> 
#define __NR_sys_hello 400 


int main(int argc, char *argv[]) 
{ 
long int a = syscall(__NR_sys_hello); 
printf("System call invoked\n");
printf("system call returned %ld\n",a); 
return 0; 

}



