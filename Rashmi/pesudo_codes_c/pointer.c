#include<stdio.h>

void mul(int *,int *,int *);
int main()
{
	int a=10,b=20,pro=1;
	int *aptr,*bptr;

	aptr=&a;
	bptr=&b;

	mul(&a,&b,&pro);
	printf("MULTIPLICATION =%d\n",pro);
}


void mul(int *a,int *b,int *pro)
{
*pro=*a * *b;
}
