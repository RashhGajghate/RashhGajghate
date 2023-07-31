#include<stdio.h>
int findelement(int *);
int i; 

int main(){
int a[]={1,2,3,4,5,6,7,8,9};
i=findelement(a);
printf("%p",a[i]);       // printing address of elements
}

int findelement(int arr[8])
{
int n1;
printf("Enter The Number");
scanf(" %d",&n1);
for(int i =0;i<= 9;i++ )
{
	if(a[i]==n1)          // Checking element 
           return i;
}
}
 



