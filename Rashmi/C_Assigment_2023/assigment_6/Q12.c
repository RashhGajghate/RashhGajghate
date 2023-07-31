#include<stdio.h>
int main()
{
	int p[3][4]={{10,20,30,50},{40,70,80,90},{100,110,120,10}};
	int (*q)[3][4];
	q=&p;
	printf("q    = %d\n",sizeof(q));
	printf("*q   = %d\n",sizeof(*q));
	printf("**q  = %d\n",sizeof(**q));
        printf("***q = %d\n",sizeof(***q));
        return 0;
}
