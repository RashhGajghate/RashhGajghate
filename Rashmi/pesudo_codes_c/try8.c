#include<stdio.h>
int main()
{
	int a=1;
	unsigned int b;
	b=sizeof(++a,a++,++a);
	printf("b = %d\n",b);
	printf("a = %d\n",a);
	return 0;
}
