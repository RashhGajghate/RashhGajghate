#include<stdio.h>

struct area
{
	int l,b,a;
};


int main()
{
struct area var;
printf("Enter the dimensions of rectangles: ");
scanf("%d%d",&var.l,&var.b);
var.a=var.l*var.b;
printf("The area of rectangle= %d\n",var.a);
return 0;
}
