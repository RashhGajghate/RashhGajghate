#include<stdio.h>

int main()
{
int i=-5,j=-2;
junk(i,&j);
printf("\n i=%d j=%d",i,j);
}
junk(int i,int *j)
{
i=i*i;
*j=*j * *j ;
}
