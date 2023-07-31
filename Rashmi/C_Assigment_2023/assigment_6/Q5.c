

#include<stdio.h>
int main()
{
	void *vptr;       //void pointer
	int a=10; 
	vptr=&a;     //assigned a integer value to void pointer  
	printf("Value           = %d\n",*(int *)vptr); //dereferencing the void pointer by typecasting it into integer pointer
        printf("Address of value= %p\n",(int *)vptr);	
	return 0;

}
