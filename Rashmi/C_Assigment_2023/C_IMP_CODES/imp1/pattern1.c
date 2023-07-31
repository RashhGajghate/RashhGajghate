#include<stdio.h>
int main()
{
	
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<=5;j++)
		{
			printf("*");
			if(i==1||i==2||i==3)
			{
				printf("    *");
				j=5;
			}
		}
		printf("\n");
	}
	return 0;
}
