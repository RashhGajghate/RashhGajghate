#include<stdio.h>
int main(){

	void *vptr;
	int arr[5]={10,20,30,40,50};
	vptr=&arr;
	for(int i=0;i<5;i++){
		printf("Value            = %d\n",*(int *)vptr+i); //Testing arithmetic operation on void pointer 
		printf("Address of value = %p\n",(int *)vptr+i);
	}
	return 0;
}
