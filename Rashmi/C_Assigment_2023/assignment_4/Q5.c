#include<stdio.h>
int hcf(int,int);
int main()
{
    int n1,n2;
    printf("Enter two number to calculate GCD:");
    scanf("%d%d",&n1,&n2);
    printf("GCD is %d\n",hcf(n1,n2)); 
}

int hcf(int a,int b){
    if (a!=0 && b!=0)
        hcf(a%b,b%a); 
    else
        return a+b;     
}


