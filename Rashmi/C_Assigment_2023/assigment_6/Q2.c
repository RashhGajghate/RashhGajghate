#include<stdio.h>
int main()
{
	short int a=0x1234;
        char *cp;
	cp=(char*)&a;

	printf("a= %x\n",a);
	printf("The little endian: \n");
	printf("*cp= %x\n",*cp);
	printf("*(cp+1)= %x\n",*(cp+1));

 
        *cp=(*cp)+(*(cp+1));
	*(cp+1)=(*cp)-(*(cp+1));
	*cp=(*cp)-(*(cp+1));

        printf("The little endian converted into big endian: \n");
	printf("*cp= %x\n",*cp);
	printf("*(cp+1)= %x\n",*(cp+1));


	
}
