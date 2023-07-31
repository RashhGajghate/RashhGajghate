#include<stdio.h>
int main()
{
	int arr[3][3],trace;
	printf("Enter the 3X3 matrix to calculate its trace= ");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
	scanf("%d",&arr[i][j]);
	printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	trace=arr[0][0]+arr[1][1]+arr[2][2];  //Finding the trace of  two matrix
	printf("The trace of given matrix= %d\n",trace);	
}
