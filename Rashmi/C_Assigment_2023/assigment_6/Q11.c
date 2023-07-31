#include<stdio.h>
int main()
{
        int arr[5]={10,20,30,40,50};
	printf("The last element of array= %d\n",*(*(&arr+1)-1));
	return 0;
}
