#include<stdio.h>
int main()
{       
	int counter=0;
	char str[20];
	char *p;
	p=str;
	printf("Enter your string: ");
	scanf("%[^\n]s",str);

	while(*p!='\0')
	{
		counter++;
		p++;
	}
	printf("The string length is %d\n",counter);
	return 0;
}
