#include<stdio.h>
int main()

{
      int (*aq)[3][2];	
	int a[3][2]={{10,20},{30,40},{50,60}};
	aq=&a;
	printf("%d\n",aq[0][1][0]);
}
