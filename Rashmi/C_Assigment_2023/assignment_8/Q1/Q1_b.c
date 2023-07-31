#include<stdio.h>
int main()
{
	char str[20];
	printf("Enter your string: ");
	scanf("%[^\n]s",str);
	char *p=str;
	printf("The copied string: %s\n",p);
	return 0;
	
}
