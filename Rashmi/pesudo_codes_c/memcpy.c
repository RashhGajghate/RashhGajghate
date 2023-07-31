#include<stdio.h>
#include<string.h>
int main()
{
	char a[20],b[20];
	char *ptr;
	scanf("%s",b);
	ptr=memcpy(a,b,10);
	printf("%s\n",a);
	printf("%s\n",ptr);
}

