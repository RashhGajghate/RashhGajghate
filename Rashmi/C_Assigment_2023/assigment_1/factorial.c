#include<stdio.h>
int main()
{
	int n=0,i,fac=1;
	    printf("Enter the no.: ");
	    scanf("%d",&n);
  for(i=n;i>0;i--)
  {
  fac*=i;
  }
  printf("Factorial of given number is %d",fac);
}

