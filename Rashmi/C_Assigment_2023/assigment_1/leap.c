#include<stdio.h>
int main()
{
	int yr,r;
	printf("Enter year: ");
	scanf("%d",&yr);
	r=yr%4;
	if(r==0)
	{
		printf("It is leap year: %d",yr);
	}
	else
	{
		printf("It is not leap year: %d",yr);
	}
}
