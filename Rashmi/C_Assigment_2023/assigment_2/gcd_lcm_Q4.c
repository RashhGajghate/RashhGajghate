#include<stdio.h>
int main()
{
	int dr,nr,lcm,hcf,rem,a,b;
	printf("Enter two number: ");
	scanf("%d %d",&a,&b);
	
	nr=(a>b)?a:b;
	dr=(a<b)?a:b;
	rem=nr%dr;

	while(rem !=0)
	{
		nr=dr;
		dr=rem;
		rem=nr%dr;
	}

	hcf=dr;
	printf("The GCD or HCF of given numbers= %d\n",hcf);
	lcm=a*b/hcf;
	printf("The LCM of given numbers= %d\n",lcm);
}
