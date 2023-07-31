#include<stdio.h>
int main()
{
	char str1[20],str2[20];

	printf("Enter two strings: ");
	gets(str1);
	gets(str2);
      
	printf("%s\n",str1);
	printf("%s\n",str2);

  if(str1==str2)
  {
	  printf("Same\n");
  }	  
else 
  {
	  printf("Not\n");
  }
  return 0;
}
