#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
	int x;
	char ch;
	 printf("Enter any alphabet: ");
         scanf("%c",&ch);
         putchar(toupper(ch));
	 printf("\n");
        printf("Enter any value: ");
	scanf("%d",&x);
	printf("Ans= %f\n",sqrt(pow(2,abs(x))));
	printf("\n");

}


