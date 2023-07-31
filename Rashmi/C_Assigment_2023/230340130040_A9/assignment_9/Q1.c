#include<stdio.h>

struct add{
	int n1,n2,sum;
};

int main()
{
struct add var;
printf("Enter two numbers: ");
scanf("%d%d",&var.n1,&var.n2);

var.sum=var.n1+var.n2;
printf("Sum of given= %d\n",var.sum);
return 0;
}
