#include<stdio.h>
void test(int,int,int *(int,int));
int (*fp)(int,int);
int main()
{
int res,x=10,y=20;
res=test(10,20,sum);
printf("res= %d\n",res);
}

void test(int x,int y,int (*fp) (int,int))
{
	int z=(int)fp(x,y);
	return fp(x,y);
}

int (*fp) (int x,int y)
{
	return x+y;
}
