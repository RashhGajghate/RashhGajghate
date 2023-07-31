#include<stdio.h>
int main()
{
	int a[5],b[5],add;

	printf("Enter the 1st array of 5 elements : ");  //Taking first array input from user
	for(int i=0;i<5;i++)
	{
	scanf("%d",&a[i]);
	printf("%d\n",a[i]);
	}
	

	printf("Enter the 2nd array of 5 elements : ");  //Taking second array input from user
	for(int j=0;j<5;j++)
	{
	scanf("%d",&b[j]);
	printf("%d\n",b[j]);
	}

 printf("Sum of two array= \n"); 
     for(int k=0;k<5;k++)
     {
	     add=a[k]+b[k];      //Adding two arrays
	     printf("%d\t",add);
     }

return 0;

}
