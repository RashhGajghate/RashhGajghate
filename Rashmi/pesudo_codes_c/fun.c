#include<stdio.h>
int add(int,int);
int main()
{
int (*fp)(int,int);
fp=add;

int ret=(*fp)(10,20);
printf("ret= %d\n",ret);
return 0;

}

int add(int a,int b)
{
	printf("In add function \n") ;

			return a+b ;
			}
