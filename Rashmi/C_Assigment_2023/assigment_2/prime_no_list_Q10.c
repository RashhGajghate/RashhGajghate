#include<stdio.h>
int main()

{
	int a,i,k,prime;
	printf("Enter the range:");
	scanf("%d",&a);
	printf("The list of prime numbers within the given range= \n");
	for (i=1; i<=a; i++)
	{
		prime=0;
	
		for (k=1; k<=a; k++)
		{
			if(i%k==0)
				prime++;
		}
		if (prime==2)
		{
			printf("%d\t",i);
	}}
	return 0;
}
