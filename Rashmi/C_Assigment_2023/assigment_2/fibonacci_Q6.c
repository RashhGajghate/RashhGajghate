#include<stdio.h>
int main()
		{
			int range,f=0,s=1,sum,fib,i;
			printf("Enter a range: ");
			scanf("%d",&range);
  
			printf("Fibonnaci series :");
			printf("\n%d",f);
			printf("\n%d",s);
                        
			sum=f+s;
			printf("\n%d",sum);

			for(i=3;i<=range;i++)
			{ 
			 f=s;
                         s=sum;
                         sum=f+s;
			 printf("\n%d",sum); 
                               
			}
			printf("\n");

		}

