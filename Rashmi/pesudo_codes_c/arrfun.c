#include<stdio.h>
int main()
{
	int arr[5]={10,20,30,40,50};

	printf("arr= %ls\n",arr);
	printf("*arr= %d\n",*arr);
	printf("arr+1= %ls\n",arr+1);
	printf("*(arr+1)= %d\n",*(arr+1));
	printf("*(1+arr)= %d\n",*(1+arr));
	printf("1[arr]= %d\n",1[arr]);
}
