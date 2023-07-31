#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	char *ptr;
	ptr=str;
	char occ;
	int counter=0,n;

	printf("Enter a string: ");
	gets(str);

	n=strlen(str);

	printf("Enter a letter to find the first occurance: ");
	scanf("%c",&occ);

hile(*ptr!==occ)
	{
		counter++;
		if(*ptr==occ)
		{
         	printf("The first occurance of letter is %d position\n",counter);
		}
	}

	return 0;
}
