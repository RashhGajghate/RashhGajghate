#include<stdio.h>
int result(int,int,int []);
int main()
{
	int n1,n2,catch,a[2];
	printf("Enter two numbers: \n");
	scanf("%d%d",&n1,&n2);
	result(n1,n2,a);
        printf("Addition of two numbers= %d\n",a[0]);
	printf("Multiplication of two numbers= %d\n",a[1]);
}

int result(int n1,int n2,int b[])
{
b[0]=n1+n2;
b[1]=n1*n2;
return &b;
}
