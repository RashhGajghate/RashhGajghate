
#include<stdio.h>
int main()
{
int a[3][3],i,j;
printf("Enter 3X3 array element : ");
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
		scanf("%d",&a[i][j]);
		printf("%d\t",a[i][j]);
	}
	printf("\n");
}
printf("Transpose of a given matrix= \n");

for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
		printf("%d\t",a[j][i]);      //Transposing 3X3 matrix
	}
	printf("\n");
}







}
