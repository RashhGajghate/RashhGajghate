#include<stdio.h>
int main()
{
	int a[2][2],b[2][2],i,j,k,l,c[2][2];

	printf("Enter 1st 2X2 matrix: ");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&a[i][j]);
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
       
       printf("Enter 2nd 2X2 matrix: ");
       for(k=0;k<2;k++)
       {
	       for(l=0;l<2;l++)
	       {
		       scanf("%d",&b[k][l]);
		       printf("%d\t",b[k][l]);
	       }
	       printf("\n");
       }

       printf("\n");

      printf("Addition of two matrix= \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			c[i][j]=a[i][j]+b[i][j];       //Addition perform on two matrix
			printf(" %d\t",c[i][j]);
		}
		printf("\n");
	}


       printf("Subtraction of two matrix= \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			c[i][j]=a[i][j]-b[i][j];    //Subtraction perform on two matrix
			printf(" %d\t",c[i][j]);
		}
		printf("\n");
	}


      printf("Multiplication of two matrix= \n");

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
		      c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j];  //Multiplication perform on two matrix
			printf("%d\t",c[i][j]);
		}
		printf("\n");

	}


}
