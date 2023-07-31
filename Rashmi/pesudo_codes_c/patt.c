#include<stdio.h>

int main()
{
/*	int x;
	printf("enter the value of x = ");
	scanf("%d",&x);

	for(int i =0 ; i < x;i++){
		for(int j = 0 ; j < x-1-i; j++){
			printf(" ");
		}
		for(int j = x ; j > x-1-i; j--){
		printf("*");
		}
		printf("\n");
	}
*/
	for(int i=0;i<5;i++){
		for(int j=5;j>i;j--){
			printf(" * ");
		}
		//for(int k=0;k<=i;k++){
		//	printf(" *");
		//}
		printf("\n");
	}
	return 0;
}
