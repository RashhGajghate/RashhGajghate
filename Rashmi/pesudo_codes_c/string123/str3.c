#include<stdio.h>
int main()
{
	char str[]="India";
        char *ptr;
	ptr=str;


	while(*ptr!='\0')
	{
	printf("str[i]= %c\n",*ptr);
	printf("&str[i]= %p\n",ptr);
	ptr++;
	}
	return 0;
}
