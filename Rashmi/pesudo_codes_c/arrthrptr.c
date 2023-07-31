#include<stdio.h>
int main()
{
	int arr[6]={10,20,30,40,50,60};
	int (*ap)[6];
	ap=&arr;
	printf("ap[0][3]= %d\n",ap[0][3]);
	printf("(*ap)[3]= %d\n",(*ap)[3]);
	printf("(((*ap)+3)=%d\n")


}
