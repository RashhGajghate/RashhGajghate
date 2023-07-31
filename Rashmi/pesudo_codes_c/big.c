#include<stdio.h>
int main()
{
	int a,i,fact=1;
printf("Enter a number: ");
scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		fact*=i;
	}
	printf("Factorial= %d\n",fact);
	return 0;
}
