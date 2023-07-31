#include<stdio.h>
int main()
{
int a,b,c;
printf("Enter the value of three no. :");
scanf("%d%d%d",&a,&b,&c);
 if(a>>b && a>>c)
 {
 printf("The biggest of three is %d\n",a);
 }

 else if(b>>a && b>>c)
 {
	 printf("The biggest of three is %d\n",b);	
 } 

 else
 {
	 printf("The biggest of three is %d\n",c);
 }


 return 0;
}
