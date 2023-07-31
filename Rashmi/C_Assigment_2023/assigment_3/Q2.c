#include<stdio.h>
int main()
{
	
	int num1,num2;
	
	printf("Enter numbers to be swapped: ");
	scanf("%d %d",&num1,&num2);
        
	num1=num1^num2;
	num2=num2^num1;
	num1=num2^num1;
	
	printf("Swaped numbers are NUM1=%d NUM2=%d\n",num1,num2);
	return 0;
}
