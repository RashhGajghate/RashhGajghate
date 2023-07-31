#include<stdio.h>
int main()
{
	int a[5]={10,20,30,40,50};

	int *p=a;
       int *q=*(&a+1)-1;

	printf("*p++   =%d\n\n",*p++);  //10
	printf("*++p   =%d\n\n",*++p);  //30
	printf("(*p)++ =%d\n\n",(*p)++);  //30
	printf("++(*p) =%d\n\n",++(*p)); //32
	printf("++*p   =%d\n\n",++*p);  //33
	printf("*(p++) =%d\n\n",*(p++));  //33
	printf("*(++p) =%d\n\n",*(++p));  //50
       
	printf("*q--   =%d\n\n",*q--);  //50
	printf("*--q   =%d\n\n",*--q); //33
	printf("--(*q) =%d\n\n",--(*q));  //32
	printf("--*q   =%d\n\n",--*q);   //31

	printf("(*q)-- =%d\n\n",(*q)--);  //31
	printf("*(q--) =%d\n\n",*(q--));  //30
	printf("*(--q) =%d\n\n",*(--q));  // 10
	 

}
