#include<stdio.h>

int main()
{
	unsigned short int a;
	printf("Enter a hexadecimal number : ");
	scanf("%hx",&a);
	a=((a >> 8) & (0x00ff)) | ((a <<8) & (0xff00));
	printf("%hx\n",a);
	return 0;
}

