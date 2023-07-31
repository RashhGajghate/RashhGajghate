#include<stdio.h>
int main()
{
	int arr[5]={10,20,30,40,50};
	int *p=arr;
	int y=*p++;
	printf("y= %d\n",y);
	printf("*p= %d\n",*p);

	p=arr;
	int z=++*p;
	p=arr;
	int r=*++p;
	printf("z= %d\n",z);
	printf("r= %d\n",r);
	return 0;
}
