#include<stdio.h>
int main()
{
	char str[]="India";
	int i=0;
	for(i=0;str[i]!='\0';i++)
	{
		printf("Character= %c\n",str[i]);
		printf("Address of characters= %p\n",&str[i]);
	}
	return 0;
}
