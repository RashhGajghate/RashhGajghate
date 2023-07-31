#include<stdio.h>
#include<stdlib.h>
void dtob(int);
void dtoo(int);
void dtoh(int);
int main(){
	int a,c=1;

	while(c!=4){
		printf("Enter number in decimal: ");
		scanf("%d",&a);
		printf("\nEnter to covert \n1.Decimal to binary \n2.Decimal to octal \n3.Decimal to hexadecimal \n4.Exit(to terminate the programme) \n ->> ");
		scanf("%d",&c);
		switch(c){
			case 1:
				dtob(a);
				break;
			case 2:
				dtoo(a);
				break;
			case 3:
				dtoh(a);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid input");
				break;
		}
	
	}
	return 0;
}
void dtob(int n){
	int b=0,m=1,rem;
	int d=n;
	while(n!=0){
		rem=n%2;
		b=b+rem*m;
		n=n/2;
		m=m*10;
	}
	printf("The binary form of %d is %09d\n",d,b);
}

void dtoo(int n){
	int b=0,m=1,rem;
	int d=n;
	while(n!=0){
		rem=n%8;
		b=b+rem*m;
		n=n/8;
		m=m*10;
	}
	printf("The octal form of %d is %03d\n",d,b);
}

void dtoh(int n){
	int m=1,rem,i=0;
	char b[20];
	int d=n;
	while(n!=0){
		rem=n%16;
		switch(rem){
			case 15:b[i]='F';
				break;
			case 14:b[i]='E';
				break;
			case 13:b[i]='D';
				break;
			case 12:b[i]='C';
				break;
			case 11:b[i]='B';
				break;
			case 10:b[i]='A';
				break;
			default:b[i]=rem*m;
			
		//b[i]=rem*m;
		}
		n=n/16;
		//m=m*10;
		i++;
	}
	printf("The hexadecimal form of %d is ",d);
	for(int j=i-1;j>-1;j--){
		if(b[j]=='A'||b[j]=='B'||b[j]=='C'||b[j]=='D'||b[j]=='E'||b[j]=='F')
			printf("%c",b[j]);
		else
			printf("%d",b[j]);
	}
	printf("\n");


}
