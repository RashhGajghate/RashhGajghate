#include<stdio.h>
 main()
{
	char ch='a';
	int i=97;
	char *ptr1=&ch;
	int * ptr2=&i;
	int flag=memcmp(ptr1,ptr2,1);
	printf("%d\n",flag);
}
