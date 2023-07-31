#include<stdio.h>
int main()
{
	int d,a=10,b=20,c=30;
	d=++a,++b,++c,a+5;
	printf("OUT= %d\n",d);
	d=(++a,++b,++c,a+5);
	printf("OUT= %d\n",d);

}
