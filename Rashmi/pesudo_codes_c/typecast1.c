#include<stdio.h>
int main()
{
	const int x=10;
	int *p;
        p=(int *)&x;
	++p;
	printf("p= %d\n",*p);
	return 0;
}
