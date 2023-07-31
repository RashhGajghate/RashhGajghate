#include<stdio.h>
int main()
{
	char str[20];
	int length;
	int year=2023;
	char buff[100];
	printf("Enter a string to find its length: ");
	scanf("%s",&str);
	length= sprintf(buff,"%s-%d",str,year);
	printf("Length: %d\n",length);
	printf("buff: %s\n",buff);
	return 0;
}
