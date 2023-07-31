#include<stdio.h>
int main()
{
	int x=10,mask=3,bit;
	printf("%d",(x & mask));
	if((x & mask)==0)
		bit = 0;
	else
		bit = 1;
	printf("%d",bit);
	return 0;
}
