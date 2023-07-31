#include<stdio.h>

struct shape{
	float radius;
	float area;
};


int main()
{
	struct shape circle[10];

	for(int i=0;i<10;i++)
	{
         printf("Enter the radius for %d circle:",i+1);
	 scanf("%f",&circle[i].radius);
	 circle[i].area=(3.14) * (circle[i].radius) * (circle[i].radius);
	 printf("The Area of %d circle= %f\n\n",i+1,circle[i].area);
	}
	return 0;
}
