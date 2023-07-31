#include<stdio.h>

struct data{
	int no;
	struct datamem{
	char alpha;
	}s1;
}var;

int main()
{
   struct data var={10,20};
   //printf("The values are %d %d\n",var.no,var.var1.no);
   return 0;
}
