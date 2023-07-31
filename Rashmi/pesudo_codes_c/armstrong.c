#include<stdio.h>
#include<math.h>
int main()
{
	while(1){
	int original_num, count=0, rem=0, sum=0;
	printf("Enter a number to find whether it is Armstrong or not ? : ");
	scanf("%d",&original_num);

	int dup_num1, dup_num2;
	dup_num1 = dup_num2 = original_num;
	
	while(dup_num1 != 0){
		dup_num1 = dup_num1/10;
		count++;
	}
	//printf("Count = %d\n",count);

	while(dup_num2 != 0){
		rem = dup_num2 % 10;
		sum = sum+pow(rem,count);
		dup_num2 = dup_num2 / 10;	
	}
	//printf("Sum = %d\n",sum);

	if(sum == original_num){
		printf("%d is Armstrong number\n\n",original_num);
	}
	else{
		printf("%d is not Armstrong number\n\n",original_num);
	}
	}
	return 0;
}
