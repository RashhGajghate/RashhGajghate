#include<stdio.h>
int main()
{
	printf("Enter the string: ");
	char a[400],ch;
	char *sptr=a;
	int count=0;
	while((ch=getchar())!=EOF)
	{
		*sptr++=ch;
		count++;
	}
	sptr= '\0';
}
