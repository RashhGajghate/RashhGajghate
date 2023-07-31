#include<stdio.h>
#include<string.h>

char *gets (char*  s);

//int puts(const char *s);

int main()
{
	printf("Enter the string \n");
	char arr[10];
        char *str;
//	char *str=arr;
	gets(arr);
	gets(str);
	puts(arr);
	puts(str);
		
	return 0;
}
