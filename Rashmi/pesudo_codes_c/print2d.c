#include<stdio.h>
int main()
{
	int a[3][4]={1,2,3,4,
		    4,3,2,1,
		    7,8,9,0};
     	printf("\n%u %u",a+1,&a+1);

	printf("\n%u %u %u",a[0]+1,*(a[0]+1),*(*(a+0)+1));
}

