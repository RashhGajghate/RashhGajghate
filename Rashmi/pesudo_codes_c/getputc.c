#include<stdio.h>
int getc(FILE *stream);
int putc(int c,FILE *stream);

int main()
{
	int c;
	c=getc(stdin);
	while(c!='x')
	{
		putc(c,stdout);
		c=getc(stdin);
	}
	return 0;
}
