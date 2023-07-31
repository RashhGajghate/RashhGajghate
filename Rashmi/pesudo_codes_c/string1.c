#include<stdio.h>
#include<string.h>
int main()
{
	char a[]="cdac-acts";
	char ar[]={'c','d','a','c','-','a','c','t','s','\0'};

	printf("a= %s\n",a);
	printf("ar= %s\n",ar);
	printf("a+1= %s\n",a+1);
	printf("ar+1= %s\n",ar+1);

	printf("strlen(a)= %ld",strlen(a));
	printf("strlen(a+1)= %ld",strlen(a+1));
	printf("sizeof= %ld",sizeof(a));
	printf("char= %c\n",*(a+4));
	printf("*a= %c\n",*a);
}
