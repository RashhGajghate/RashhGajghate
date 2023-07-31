#include<stdio.h>
int main()
{
	int arr[]={10,20,30,40,50};
	printf("%u %u\n",arr,&arr);

	printf("%u %u\n",arr+1,&arr+1);
}
