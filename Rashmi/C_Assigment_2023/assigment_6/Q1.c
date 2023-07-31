#include<stdio.h>
int main()
{
	int x=0x11223344;
	char *ch;
	ch=(char *)&x;
	printf("X= %x\n",x);
	printf("*ch= %x\n",*ch);  //*ch=44

	printf("*(ch+1)= %x\n",*(ch+1));  //*(ch+1)=33

	printf("*(ch+2)= %x\n",*(ch+2)); //*(ch+2)=22

	printf("*(ch+3)= %x\n",*(ch+3)); //*(ch+3)=11, So the current system using Little endian which storing lower address at lower byte

}
