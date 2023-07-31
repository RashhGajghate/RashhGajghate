#include<stdio.h>
int main()
{
	char *str="cdac acts desd";
//	printf("%c\n",*str++);
//	printf("%c\n",*str);

	while(*str!='\0')
	{       
		
		printf("%c\n",*str);
		*str++;
	}
	return 0; 
}
