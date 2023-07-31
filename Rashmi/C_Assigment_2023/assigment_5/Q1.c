#include<stdio.h>
int array(int [],int);
int main()
{
	int arr[10],num,j;
	printf("Enter 10 input: ");
	for(j=0;j<10;j++)
	{
	scanf("%d",&arr[j]);
	}

	printf("Enter a input to check whether it is present or not : ");
	scanf("%d",&num);

        array(arr,num);
	return 0;
}

int array(int b[], int num)
{
	int i, flag=0;
	for(int i=0;i<10;i++)
	{ 
	
	//	printf("i= %d\n",i);
		if(num==b[i])
		{
		flag=1;
		break;
		}
	}
		if(flag==1)
		{
			printf("Element is present\n");
	       	}
		else
		{
			printf("Element is not present");
			return -1;
		} 
	
} 
