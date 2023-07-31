#include<stdio.h>
int main()
{
	int i,j;
	for(i=0;i<=4;i++)
	{
		for(j=0;j<=4;j++)
		{
			printf("8");
			if(i==1||i==3)
			{
				printf("   8");
				j=4;
			}
		}
		printf("\n");
	}
	return 0;
}

