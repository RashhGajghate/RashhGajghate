#include<stdio.h>
int main()
{
	while(1){
		int num, perfect_number=0;
		printf("Enter a number : ");
		scanf("%d",&num);

		for(int i=1;i<num;i++){
			if(num % i == 0)
				perfect_number = perfect_number + i;
		}

		if(perfect_number == num)
			printf("%d is a perfect number\n\n",num);
		else
			printf("%d is not a perfect number\n\n",num);
		}
	return 0;
}
