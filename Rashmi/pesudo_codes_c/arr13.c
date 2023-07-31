#include<stdio.h>
int main()
{
	int arr[5]={10,20,30,40,50};

	printf("arr= %u\n",arr);
	printf("*arr= %u\n",*arr);
	printf("(arr+1)= %u\n",(arr+1));
	printf("*(arr+1)= %u\n",*(arr+1));
	printf("*(1+arr)= %u\n",*(1+arr));
	printf("1[arr]= %u\n",1[arr]);
	printf("arr[1]= %u\n",arr[1]);
}
