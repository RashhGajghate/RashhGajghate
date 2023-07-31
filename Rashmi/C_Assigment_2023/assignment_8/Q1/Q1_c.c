#include<stdio.h>
int main()
{
	char str1[20],str2[20];
	char *ptr;
	ptr=str1;
	printf("Enter two strings: ");
	gets(str1);
	gets(str2);
	while(*ptr!='\0')
	{
		printf("%c",*ptr);
		ptr++;

		if(*ptr=='\0')
		{
			printf("%s",str2);
		}
	}
return 0;
}
