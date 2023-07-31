#include<stdio.h>
int main()

{
	int k,i=20,y,x=5,p=9,q;
	k=i++;
	printf("K= %d\n",k);
	k=++i;
	printf("K= %d\n",k);

	y=x++*10;
       	printf("Y= %d\n",y);
	y=++x*10; 
	printf("Y= %d\n",y);

	q=p--/3;
	printf("Q= %d\n",q);
        q=--p/3;
	printf("Q= %d\n",q);
}
