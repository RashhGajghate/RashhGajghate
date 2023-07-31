#include<stdio.h>
void user_input(int *,int);
void print(int *, int);
int main()
{
int size;
printf("Enter array size: ");
scanf("%d",&size);
int arr[size];
user_input(arr,size);
print(arr,size);
return 0;
}

void print(int *b,int size)
{
	printf("Array element as count= %d\n",size);
	for(int i=0;i<size;i++)
	{
		printf("%d\t",*(b+i));
	}
}


void user_input(int *b,int size)
{
	printf("Array element as count= %d\n",size);
	for(int i=0;i<size;i++)
	{
		scanf("%d",*(b+i));
	}
}


