#include<stdio.h>
void con(int,int);
int main()
{
int num,base;
printf("Enter a positive decimal value: ");
scanf("%d\n",num);
printf("Enter base: ");
scanf("%d",&base);

printf("\n Binary number: ");
con(num,2);
printf("\n");

printf("\n Octal number: ");
con(num,8);
printf("\n");

printf("\n Hexadecimal number: ");
con(num,16);
printf("\n");
}

void con(int num,int base)
{
	int rem=num%base;

	if(num==0)
		return 0;
	con(num/base,base);

	if(rem<10)
		printf("%d",rem);
	else
		printf("%c",rem-10+'A');
}
	
