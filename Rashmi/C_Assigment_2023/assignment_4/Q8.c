#include<stdio.h>
int findOnes(int);
int findZeros(int);
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("number of ones in this number is %d\n",findOnes(n));
    printf("number of zeros in the number is %d\n",findZeros(n));
    return 0;
}

int findOnes(int a){
    int ones=0;
    if(a!=0){
        if(a&1)
            ones=1;
        ones+=findOnes(a>>1);
    }
    return ones;
}

int findZeros(int a){
    int zeros=0;
    if(a!=0){
        if(!(a&1))
            zeros++;
        zeros+=findZeros(a>>1);
    }
    return zeros;  
}


