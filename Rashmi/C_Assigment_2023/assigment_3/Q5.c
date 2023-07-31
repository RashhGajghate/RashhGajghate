#include<stdio.h>
int time(int,int,int);
int main()
{
	int h,m,s,take;
	printf("Enter a time foramte(hh:mm:ss): ");
	scanf("%d",&h);
	scanf("%d",&m);
	scanf("%d",&s);
	take=time(h,m,s);
}

    int time(int h, int m, int s)
    {
	    int hs,ms,ns;
        hs=h*3600;
	 ms=m*60;
	ns=hs+ms+s;
	printf("OUTPUT= %d\n",ns);
	return ns;
    }


