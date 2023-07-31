#include<stdio.h>
int main()
{
   char str[]="India";
   char str1[20];
   printf("Enter a string: ");
   char *p;
   p=&str1;
   scanf("%[^\n]s",str1);
   
   printf("The letters are: ");
   for(int i=0;str[i]!='\0';i++)
   {
	   printf("%c\t",str[i]);
   }
  printf("\n"); 

   while(*p!='\0')
   {
	   printf("%c\t",*p);
	   *p++;
   }
 

return 0;
}
