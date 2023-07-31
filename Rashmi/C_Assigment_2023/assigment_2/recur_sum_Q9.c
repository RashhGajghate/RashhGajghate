#include<stdio.h>
int add(int);
int main()
{
	int n,ans,res=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	ans=add(n);	
	printf("Sum of digits= %d\n",ans);
}

	int add(int n)
	{
		if(n!=0)
		{
			int res=(n%10+add(n/10));
			return res;		
		}
		else
		{  	
		return 0;
		}
}	
	


	
