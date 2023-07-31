#include<stdio.h>
int sum(int);
int main()
{
	int num,ans=0;
	printf("Enter a range of a number: ");
	scanf("%d",&num);
	ans=sum(num);
	printf("ANSWER= %d\n",ans);
}

int sum(int num)
{
	int i,add=0,r;
	if(num!=0)
	{
        for(i=1;i<=num;i++)
        add+=i;
	}
	else
	{
          printf("Enter some range : ");
	  scanf("%d",&r);
	  add=sum(r);
	}
  return add;
}	



