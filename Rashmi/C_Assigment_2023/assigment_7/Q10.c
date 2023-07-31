#include<stdio.h>
int sum(int,int);
int diff(int,int);
int mul(int,int);

int main()
{
int (*fp)(int,int);      //fp is a function pointer taking two paramters as integer and returning integer
fp=sum;
int res=(*fp)(10,20);
printf("res= %d\n",res);

typedef int(*fptr)(int,int);        //typedef the pointer function fptr taking two parameters as integer and returning integer
 fptr fp1=diff;
 fptr fp2=mul;

 res=(*fp1)(10,20);
 printf("res= %d\n",res);

 res=(*fp2)(10,20);
 printf("res= %d\n",res);

return 0;
}



int sum(int a,int b){
	return a+b;}

int diff(int a,int b){
	return a-b;}

int mul(int a,int b){
	return a*b;}






