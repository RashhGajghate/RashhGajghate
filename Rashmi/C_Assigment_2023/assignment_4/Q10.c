#include<stdio.h>
int digits(int);
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("digits present in %d are %d",n,digits(n));
    return 0;
}

int digits(int a){
    int res=0;
    if(a)
        res+=1+digits(a/10);    
    return res;
}


