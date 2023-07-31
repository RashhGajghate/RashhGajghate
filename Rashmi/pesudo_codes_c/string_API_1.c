#include<stdio.h>
int getchar(void);
int putchar(int c);
int main()
{
	int c;
	c=getchar();
	while(c!=EOF)
	{
		putchar(c);
		//c=getchar();
	}
	return 0;
}
