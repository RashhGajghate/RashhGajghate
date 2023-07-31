#include<stdio.h>
#include<stdlib.h>
void bin(int);
void oct(int);
void hex(int);
int main(){
	int a,c=1;

	//while(c!=4){
		printf("Enter number in decimal: ");
		scanf("%d",&a);
	/*	printf("\nEnter to covert \n1.Decimal to binary \n2.Decimal to octal \n3.Decimal to hexadecimal \n4.Exit(to terminate the programme) \n ->> ");
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
		}*/

                int ans_bin=bin(a);
		int ans_oct=oct(a);
		int ans_hex=hex(a);
		printf("Binary= %d\n",ans_bin);
		printf("Octal= %d\n",ans_oct);
		printf("Hexadecimal= %d\n",ans_hex);
	
	//}
	return 0;
}
void bin(int a){
	int b=0,m=1,rem;
	int d=a;
	while(a!=0){
		rem=a%2;
		b=b+rem*m;
		a=a/2;
		m=m*10;
	}
	printf("The binary form of %d is %09d\n",d,b);
}

void oct(int a){
	int b=0,m=1,rem;
	int d=a;
	while(a!=0){
		rem=n%8;
		b=b+rem*m;
		a=a/8;
		m=m*10;
	}
	printf("The binary form of %d is %09d\n",d,b);
}

void hex(int a){
	int m=1,rem,i=0;
	char b[20];
	int d=a;
	while(a!=0){
		rem=a%16;
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
			
		}
		a=a/16;
		i++;
	}
	printf("The binary form of %d is ",d);
	for(int j=i-1;j>-1;j--){
		if(b[j]=='A'||b[j]=='B'||b[j]=='C'||b[j]=='D'||b[j]=='E'||b[j]=='F')
			printf("%c",b[j]);
		else
			printf("%d",b[j]);
	}
	printf("\n");


}
