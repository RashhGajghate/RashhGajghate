#include<stdio.h>
int main(){
int n;
printf("enter the size");
scanf("%d",&n);

for(int i=1 ; i<=n;i++){
        for(int j=1;j<=n;j++){
	if(i==j){                          // logic to print identity matrix
	printf("1");
	}
	else
		printf("0");
	}
        printf("\n");
	}
printf("\n");

for(int i=1 ; i<=n;i++){
        for(int j=1;j<=n;j++){
	if(i==j){                        
	printf("0");                       // logic to print null matrix
	}
	else
		printf("0");
	}
        printf("\n");
	}





}
