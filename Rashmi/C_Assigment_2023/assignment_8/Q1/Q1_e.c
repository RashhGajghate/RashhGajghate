#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	int i,n,temp=0;
	char *p;
	p=str;
	printf("Enter a string: ");
	scanf("%s",str);
	n=strlen(str);
	for(i=0;i<=n;i++)
	{
	printf("%c\n",str[n-i]);
	}
	return 0;
}
