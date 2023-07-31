#include<stdio.h>
int main()
{
	int arr[5]={10,20,30,40,50,};
	int (*ap)[5];
	int (*ar)[2];
	ap=&arr;
	ar=&arr;
	printf("ap= %p\n",ap);
	printf("ap+1= %p\n",ap+1);
	printf("ar= %p\n",ar);
	printf("ar+1= %p\n",ar+1);
	return 0;
}
