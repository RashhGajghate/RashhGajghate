#include<stdio.h>
int main()
{
	int n,c=0,i;
	printf("Enter a number: ");
	scanf("%d",&n);
       for(i=1;i<=n;i++)
       {
        if(n%i==0)
	       {
		       c++;
	       }
       }

       if(c==2)
       {
	       printf("It is prime number\n");
       }
       else
       {
	       printf("It is not prime number\n");
       }
}
