#include<stdio.h>
int sum(int,int);
int diff(int,int);
int mul(int,int);
int main()
{
int (*fp[])(int,int);
int a,b,choice;
printf("Enter two numbers: ");
scanf("%d%d",&a,&b);
fp[choice]=sum;
fp[choice]=diff;
fp[choice]=mul;
return 0;
}


int sum(int a,int b)
{
	return a+b;
}

int diff(int a,int b)
{
	return a-b;
}

int mul(int a,int b)
{
	return a*b;
}
