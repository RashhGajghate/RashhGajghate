#include<stdio.h>
void display(int (*)[3]);
int main()
{
	int a2[2][3]={{10,20,30},{40,50,50}};
	display(a2);
	return 0;
}

void display(int (*b)[3])
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
