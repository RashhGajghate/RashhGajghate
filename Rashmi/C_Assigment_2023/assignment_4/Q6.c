#include<stdio.h>
void fib(int );
int main()
{
	int num;
	printf("Enter the range for to print fibonacci series\n");
	scanf("%d",&num);
	printf("The fibonacci series: ");
	fib(num);                  //call to print fibonacci
	return 0;
}
void fib(int n){
	static int a=-1,b=1,c;
	if(n==0){              //to exit when operation completed
		
	}
	else{
		c=a+b;
		a=b;
		b=c;
		printf("%d ",c);            //fibonacci variable
		fib(--n);
	}
}
