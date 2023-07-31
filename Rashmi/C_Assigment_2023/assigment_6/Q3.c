#include<stdio.h>
int main()
{
	int n=0x12345678;
	int rev;
	char*cp;
	cp=(char*)&n;
	printf("n= %x\n",n);

        printf("The little endian: \n");
/*	printf("%x\n",*cp);
	printf("%x\n",*(cp+1));
	printf("%x\n",*(cp+2));
	printf("%x\n",*(cp+3));  */

 for(int i=0;i<4;i++)
 {
       	printf("*(cp+i)= %x\n",*(cp+i));
	 printf("%p\n",&(*(cp+i)));
 }
printf("The conversion of little endian to big endian: \n");
 for(int i=3;i>=0;i--)
 {
	 rev=*(cp+i);
	 printf("*(cp+i)= %x\n",*(cp+i));
	 printf("%p\n",&(*(cp+i)));
 }
   
	
	return 0;
}
