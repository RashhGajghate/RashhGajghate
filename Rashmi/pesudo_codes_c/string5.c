#include<stdio.h>
int mystrlen(const char *);
int mystrcpy(char *,const char *);
int main()
{
char name[]="abcde";
char buff[20];
int len=mystrlen(name);
printf("len= %d\n",len);

mystrcpy(buff,name);
printf("buff= %s\n",buff);

}




int mystrlen(const char *cp)
{
	int counter=0;
	while (*cp!='\0')
	{
		cp++;
		counter++;
	
	}
	return counter;
}



int mystrcpy(char *dest,const char *src)
{
	while(*src!='\0')
	{
		*dest=*src;
		++dest;
		++src;
	}
	*dest='\0';
}


