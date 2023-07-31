#include<stdio.h>
#include<string.h>

int main()
{
	//int counter=0;
	char str[]="Rashmi";
	char str1[]="Nagpur";
        //char *p;
	//p=&str1;
	printf("The length of str= %d",strlen(str));
     
	int i=0;
	while(str1[i]!='\0')
	{
         i++;
	}
	printf("The length of str1= %d",i);

	return 0;


}
