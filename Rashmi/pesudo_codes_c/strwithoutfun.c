#include<stdio.h>
int mystrlen(char *);
void mystrcpy(char *, const char *);
int main()
{
	char name[]="rashhme";
	char buff[20];
	int len=mystrlen(name);
	printf("The length= %d\n",len);

	mystrcpy(buff,name);
	printf("Copied string= %s\n",buff);
}


int mystrlen(char *a)
{
	int counter=0;
	while(*a!='\0')
	{
		a++;
		counter++;
	}
	return counter;
}



void mystrcpy(char *dest, const char *src)
{
	
	while(*src!='\0')
	{ 
		*dest=*src;
		src++;
		dest++;
		
	}
	dest='\0';

}













