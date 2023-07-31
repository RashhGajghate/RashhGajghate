#include<stdio.h>
int main()
{
	register int x=10;
	printf("The stored value= %d\n",x);
	//printf("The address of value stored in register: %p\n",&x);  //We cannot print the address of register variable since it is present in register
	                                                               //and not in memory 
}                                                                     

                                                                       //We can use registers only in local, it is not used in global or outside the main
