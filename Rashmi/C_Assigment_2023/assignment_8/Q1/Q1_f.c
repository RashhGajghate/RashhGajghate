#include<stdio.h>
int main()
{
	char str[20];
	char *ptr;
	ptr=str;
	char occ;
	int counter=1;

	printf("Enter a string: ");
	gets(str);

	printf("Enter a letter to find the first occurance: ");
	scanf("%c",&occ);

        while(*ptr!=occ)
	{	
              counter++;
	      ptr++;
	}
	printf("The first occurance of letter is %d position\n",counter);
	return 0;
}
