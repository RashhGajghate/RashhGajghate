#include<stdio.h>

int top(int);
int middle(int);
int bottom(int);


void main()
{
 int call1,call2,call3;
 int a,i,n;
 printf("Enter a number : ");
 scanf("%d",&a);


 while(a>0)
 {
	 n=a%10;
 }
 printf("n= %d\n",n);
 
 call1=top(a);
 call2=middle(a);
 call3=bottom(a);

printf("%d",call1);
printf("%d",call2);
printf("%d",call3);
 
}


int top(int a)
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



int middle(int a)
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



int bottom(int a)
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






