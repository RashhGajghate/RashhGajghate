#include<stdio.h>
int main()
{
	char str[20];
	char alp;
	char *ptr;
	ptr=str;
	int counter=0;
	printf("Enter a string: ");
	gets(str);
	printf("Enter a character for counting occurence: ");
	scanf("%c",&alp);
     
	while(*ptr==alp)
	{
		counter++;
		ptr++;
	}
	printf("last occurance at %d position\n",counter);
        
       return 0;



}
