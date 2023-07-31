#include<stdio.h>

struct arr{
	float len;
	float bd;
        float a;
};


int main()
{
  struct arr var[3];
  printf("Enter the dimensions for length and breadth of 3 reactangles to calculate the AREA: ");
  for(int i=0;i<3;i++)
  {
  scanf("%f %f",&var[i].len,&var[i].bd);
  var[i].a=var[i].len*var[i].bd;

  printf("The AREA of rectangles= %f\n",var[i].a);
  }
return 0;

}
