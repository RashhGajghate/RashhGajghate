#include<stdio.h>
int a,i,j;
int main ()
{
	printf("enter the number :");
        scanf ("%d",&a);
	
	for (i=1;i<=a;i++)
	{
            for(j=1;j<=a;j++)
	{
		if(j<=a-i)
		{
			printf(" ");
		}
		else
		{
			printf("%d",i);
		}
	    
	}	
	    printf("\n");
	}
	
}
