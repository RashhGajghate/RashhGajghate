#include<stdio.h>

void add(int *,int *,int *);
int main()
{
	int a=10,b=20,sum=0;
	int *aptr, *bptr;
	aptr=&a;
	bptr=&b;
	add(&a,&b,&sum);
	printf("Sum= %d\n",sum);
}


void add(int *a,int *b,int *sum)
{
	*sum=*a+*b;
}
