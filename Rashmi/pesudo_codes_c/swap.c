#include<stdio.h>
int main()
{
	int x,y;
	printf("Enter two numbers: ");
	scanf("%d%d",&x,&y);

	x=x+y;  //x=10,y=20  x=30
	y=x-y; //30-20=10
        x=x-y;

	printf("%d %d",x,y);
		
}


