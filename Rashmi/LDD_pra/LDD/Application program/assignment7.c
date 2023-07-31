
//Write an application program to take one unsigned int a=0xaabbccdd, retrieve and print values separately using MAJOR MACRO like "aab“  and MINOR MACRO like "bccdd”?
#include<stdio.h>
#define MAJOR(x) (x>>20)
#define MINOR(x) (x & (0x000fffff))

int main()
{
	unsigned int a=0xaabbccdd;
	printf("MAJOR MACRO = %x\n",MAJOR(a));
	printf("MINOR MACRO = %x\n",MINOR(a));
	return 0;
}
