#include<stdio.h>
	#inclide<sys/syscall.h>
	int main(){
		printf(“Entered main function…!\n”);

		/*here starts system call*/
		syscall(“SYS_mycall”);

		printf(“System call invoked, to see type command: dmesg at your terminal\n”);
		printf(“Exiting main….!\n)

		return 0;
	}

