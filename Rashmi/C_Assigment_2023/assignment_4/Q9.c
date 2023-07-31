#include<stdio.h>
int Pow(int,int);
int main(){
    int n, p;
    printf("Enter the base and then power: ");
    scanf("%d%d",&n,&p);
    printf("OUTPUT= ");
    printf("%d^%d = %d",n,p,Pow(n,p));
    return 0;
}

int Pow(int a, int b){
    int res=a;
    if(--b)
        res*=Pow(a,b);
    return res;
}   


