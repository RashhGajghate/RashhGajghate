#include<stdio.h>
int main()
{
	int i,num=0xA0DF;
	for(i=31;i>=0;i--)
		printf("%x\n",(num>i)&1);
	return 0;
}
