#include<stdio.h>
int main()
{
	int a,b,c,ans1,ans2,ans;
		printf("Enter three number: ");
	        scanf("%d%d%d",&a,&b,&c);

		ans1=a>b?a:b;
		ans2=a>c?a:c;
		ans=ans1>ans2?ans1:ans2;
		printf("ANSWER= %d\n",ans);

}
