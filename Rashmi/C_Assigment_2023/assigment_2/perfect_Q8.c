#include<stdio.h>
int main()
{
	int a,i,sum=0,per;
	printf("Enter a number: ");
	scanf("%d",&a);

	for(i=1;i<=a;i++)
	{
		if(a%i==0)
		{
			sum+=i;
		}
	}
     per=sum/2;
     if(a==per)
     {
	     printf("It is a perfect number \n");
     }
     else
     {
	     printf("It is not a perfect number \n");
     }
}
