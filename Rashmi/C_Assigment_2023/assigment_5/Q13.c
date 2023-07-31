#include<stdio.h>
int main()
{
	int arr[3][3],mat,i=0,j=0,check=0,counter=0;
	printf("Enter a 3X3 matrix= ");         //Taking user input
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&arr[i][j]);

			check=arr[i][j];
			if(check==0)
			{
				counter++;

                 	}

         	}
}
if(counter==9)         //Whether the matrix is null or not
{
	printf("It is null matrix \n");
}
else
{
	printf("It is not null matrix \n");
}

}

