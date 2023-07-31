#include<stdio.h>
int main()
{
	int arr[5]={10,20,30,40,50};
	int *p=arr;

	printf("p= %d\n",p);
	printf("*p++= %d\n",*p++);
	printf("p= %d\n",p);
	printf("*p= %d\n",*p);
	return 0;
}

