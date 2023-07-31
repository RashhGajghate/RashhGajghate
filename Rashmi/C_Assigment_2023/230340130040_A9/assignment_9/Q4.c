#include<stdio.h>

float ans(float,float);

struct area{
	float len;
	float bre;
	float ar;
};

int main()
{
	struct area var;
	printf("Enter length and breadth of rectangle: ");
	scanf("%f %f",&var.len,&var.bre);
	var.ar=ans(var.len,var.bre);
	printf("The AREA of rectangle= %f",var.ar);
        return 0;
}

float ans(float len,float bre)
{
	return len*bre;
}

