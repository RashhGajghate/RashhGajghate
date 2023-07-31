#include<stdio.h>
#include<string.h>
int main()
{
char name[10];
char buff[20];

printf("Enter a string : ");
scanf("%[^\n]s",name);
printf("%s\n",name);

int len=strlen(name);
printf("len= %d\n",len); //8

strcpy(buff,name);
printf("buff= %s\n",buff); //rashh me

printf("strlen(buff)= %ld\n",strlen(buff)); //8
printf("sizeof(buff)= %ld\n",sizeof(buff)); //20

name[0]='A';
	printf("%s\n",name);


}
