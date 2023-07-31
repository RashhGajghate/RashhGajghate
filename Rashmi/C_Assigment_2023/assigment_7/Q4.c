#include<stdio.h>
int swap(int *,int *);
int swap2(int,int);
int main()
{     
	int a,b;
	printf("Enter two number to swap: ");
	scanf("%d%d",&a,&b);
	swap(&a,&b);
	printf("The swapped values by passing reference \n");
	printf("a= %d\n",a);
	printf("b= %d\n",b);
	
	swap2(a,b);
	printf("The swapped values by passing values \n");
	printf("a= %d\n",a);
	printf("b= %d\n",b);
}

 //Pass by reference      
int swap(int *i,int *j)
{
	*i=*i+*j;
	*j=*i-*j;
	*i=*i-*j;
}
 


//Pass by value
int swap2(int a,int b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}
