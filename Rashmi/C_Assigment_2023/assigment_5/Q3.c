#include<stdio.h>
int main()
{
	int arr[5],ans;
	printf("Enter an array of five elements: ");
	for(int i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
		printf("%d %p\n",arr[i],&arr[i]);
	}

	printf("\n");
printf("The reverse array in memory= \n");
for(int j=4;j>=0;j--)
printf("%d %p\n",arr[j],&arr[j]);

}

