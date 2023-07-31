#include<stdio.h>
#include<string.h>

int main()
{
	char str[20];
	char str1[20];

	printf("Enter 1 strings: ");
	scanf("%s",str);
	printf("Enter 2 strings: ");
	scanf("%s",str1);

	//printf("str= %s\n",str);
	//printf("str1= %s\n",str1);
	

       if(strcmp(str,str1)==0)
       {
	       printf("same");
       }
       else
       {
	       printf("not same");
       }

       
	return 0;
}
