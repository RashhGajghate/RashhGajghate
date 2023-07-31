#include<stdio.h>
int main()
{
	int a[5]={10,20,30,40,50};
	int *ptr=(int *)(&a+1);
         int *q=*(&a+1)-1;
	 printf("*q= %d\n",*q);
	printf("%d\n%d\n",*(a+1),*(ptr-1));
}
