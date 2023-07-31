#include<stdio.h>
int main()
{
	int a=10;
	int *aptr;
	aptr=&a;

	printf("&a= %d\n",&a);

	printf("a= %d\n",a);
	printf("*aptr= %d\n",*aptr);
	printf("aptr= %d\n",aptr);
	printf("&aptr= %d\n",&aptr);
}
