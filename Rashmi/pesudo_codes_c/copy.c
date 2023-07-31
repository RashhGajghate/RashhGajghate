#include<stdio.h>

int top(int *);
int middle(int *);
int bottom(int *);


int main()
{
 char call1,call2,call3;
 char a[10];
 printf("Enter a number : ");
 scanf("%s",&a);
 
 call1=top(a);
 call2=middle(a);
 call3=bottom(a);

printf("%s",call1);
printf("%s",call2);
printf("%s",call3);
}


char top(int *a)
{
	if(a==1 || a==4)
	{
		printf(" \n");
	}
	else if( a==3 || a==7)
	{
		printf("_\n");
	}
	else if(a==2)
	
	{
		printf(" _\n");
	}

	else
	{
		printf(" _\n");
	}
}



char middle(int *a)
{
	if(a==0)
	{
		printf("| |\n");
	}
	else if(a==1 || a==7)
	{
		printf(" |\n");
	}
	else if(a==3)
	{
		printf("_|\n");
	}
	else if(a==5 || a==6)
	{
		printf("|_\n");
	}
	else if(a==2)
	{
		printf(" _|\n");
	}
	else
	{
		printf("|_|\n");
	}
}



char bottom(int *a)
{
	if(a==0)
	{
		printf("|_|\n");
	}
	else if(a==1 || a==7)
	{
		printf(" |\n");
	}
	else if(a==4)
	{
		printf("  |\n");
	}
	else if(a==5 || a==9)
	{
		printf(" _|\n");
	}
	else if(a==3)
	{
		printf("_|\n");
	}
	else if(a==8 || a==6)
	{
		printf("|_|\n");
	}
	else
	{
		printf("|_\n");
	}
}






