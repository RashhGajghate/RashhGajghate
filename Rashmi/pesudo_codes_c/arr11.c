#include<stdio.h>
int add(int,int);
int main()
{
	int a=10,b=20;
	printf("In main &a=%u &b=%u\n",&a,&b);
	int res=add(a,b);
printf("Res=%d\n",res);
return 0;
}

int add(int a,int b)
{
	printf("In add &a=%u &b=%u\n",&a,&b);
	int c=a+b;
	return c;
}
