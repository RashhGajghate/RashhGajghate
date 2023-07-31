#include<stdio.h>
int main()
{
	int n,sum=1,i,avg=1;
	printf("Enter a range: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=i;                      
	}
	printf("Sum= %d\n",sum);
	avg=sum/n;
   printf("Average= %d\n",avg);

}
