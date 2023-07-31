#include<stdio.h>
int counter(int);
int main()
{
	int i,j;
	for(i=0;i<=5;i++)
	j=counter(i);
	printf("%d\n",j);
}
int counter(int i)
{
	static int count=0;
	count=count+i;
	return(count);
}
