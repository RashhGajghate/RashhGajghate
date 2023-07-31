#include<stdio.h>
int main()
{
	int i=10;
	printf("%d",i);
	{
		int i=20;
		printf("%d",i);
	}
	printf("%d",i);
}
