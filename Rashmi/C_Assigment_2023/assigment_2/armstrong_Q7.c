#include<stdio.h>
#include<math.h>
int main()
{
	int a,q1,q2,r1,r2,p1,p2,p3,sum=0;
	printf("Enter a three digit number to check it is Armstrong or not: ");
	scanf("%d",&a);
        q1= a/100;
        r1=a%100;

	q2=r1/10;
	r2=a%10;
	 
      p1=pow(q1,3);
      p2=pow(q2,3);
      p3=pow(r2,3);

      sum=p1+p2+p3;
     // printf("%d\n",sum);

      if(sum==a)
      {
	      printf("The number is armstrong \n");
      }
      else
      {
	      printf("The number is not armstrong \n");
      }
}
