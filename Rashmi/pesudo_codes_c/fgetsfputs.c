#include<stdio.h>
char *fgets(char *s, int size,FILE *stream);
int fputs(const char *s,FILE *stream);

int main()
{
	char arr[10];
	char *str;
	str=fgets(arr,10,stdin);
	fputs(str,stdout);
	fputs(arr,stdout);
}
