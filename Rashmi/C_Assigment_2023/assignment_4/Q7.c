#include<stdio.h>
long long int decToBin(int);
long int decToOct(int);
void decToHex(char *, int);

int main()
{
    int n;
    long int bin,oct;
    char hex[6];
    printf("Enter a number to convert in binary, hex and octal: ");
    scanf("%d",&n);
    printf("Binary      = %lld\n",decToBin(n));
    printf("Octal       = %ld\n",decToOct(n));
    printf("Hexadecimal =");
    decToHex(hex,n);
    int x=sizeof(hex);
    for(int i=x-1;i>=0;i--)
        printf("%c",hex[i]);
    return 0;
}

long long int decToBin(int a)  //Binary
{
    long long int bin=0;
    if(a>0){
        bin=a%2+10*decToBin(a/2);
    }
    return bin;
}

long int decToOct(int a)  //Octal
{
    long int oct=0;
    if(a>0){
        oct=a%8+10*decToOct(a/8);
    }
    return oct;
}

void decToHex(char *arr, int a)    //Hexadecimal
{
    if(a>0){
        if(a%16>9)
            *(arr++)=a%16+55;
        else
            *(arr++)=a%16+48;
        *arr='\0';
        decToHex(arr,a/16);
    }
}


