#include<stdio.h>
int main()
{
	int arr[5]={10,20,30,40,50};
	int(*ap) [5];
	ap=&arr;
	printf("arr= %ls\n",arr);
	printf("ap= %p\n",ap);
	printf("arr+1= %p\n",arr+1);
	printf("*(arr+1)= %d\n",*(arr+1));
	return 0;
}
