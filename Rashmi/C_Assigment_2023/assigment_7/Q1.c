#include<stdio.h>
int f(int);
int main()
{   
	int n;
	printf("Enter a value: ");
	scanf("%d",&n);
	printf("Inside main function \n");
        printf("f(n)= %d\n",f(n));
}


int f(int n)
{
	int x;
	static int counter=0;
	if(n==0)
	x=0;
	else
	{
	x=n+f(n-1);   //for n=2, its is taking f(2-1)=f(1) then giving x
	counter++;
	}
	printf("In function f(%d)\n= ",n);
	printf("The function call count= %d\n",counter);   //since it is static variable it is retaining the previous value counter=0,1,2,3,...
	printf("\n");                                      //If we make it a global it also retain the value counter=0,1,2,3,...
	return x;                                          //In auto it is not retaining the previous value counter=0,1,1,1,......
}
