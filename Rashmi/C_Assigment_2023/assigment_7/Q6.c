#include<stdio.h>
#include<stdlib.h>
int *test(int);
int main()
{
       int x;
       int *ptr1;
       printf("Enter a value: ");
       scanf("%d",&x);
       ptr1=test(x);
       printf("Y= %d\n",*ptr1);  //function can not returns the address of variable local to function
       return 0;
}
	int *test(int x)
	{
		int y;
		int *ptr=(int *)malloc(sizeof(int));
		ptr=&y;
		y=x*x;
		return ptr;
	}

