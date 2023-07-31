#include<stdio.h>
int fact(int);
int main()
{
	int num,show;
	printf("Enter a number: ");
	scanf("%d",&num);
       
	show=fact(num);
	printf("Factorial of a number=  %ld\n",show);

}    


int fact(int num)
{
       int pro=1;	
	
	if(num>=0)
	{
	
	for(int i=1;i<=num;i++)
	{
		pro*=i;
	}
	return pro;
	}
	else
	{
		num=num+1;
		pro=fact(num)*0;

		return pro;
	}

}
  

       
