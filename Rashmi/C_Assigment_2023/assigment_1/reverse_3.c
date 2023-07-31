#include<stdio.h>
int main(){

	int a,q1,q2,q3,r1,r2;
	printf("Enter a three digit no. : ");
	scanf("%d",&a);
	q1=a/10;
	r1=a%10;

	q2=q1/10;
	r2=q1%10;

	q3=q2%10;
	printf("Value : %d%d%d",r1,r2,q3);
	

	return 0;
}

