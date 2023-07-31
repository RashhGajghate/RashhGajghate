#include<stdio.h>
#include<string.h>
int main()
{
char name[10];
char buff[20];
char *str;
str=name;

char *cp;

printf("Enter a string : ");
scanf("%[^\n]s",name);
printf("%s\n",str);

printf("strlen(str)= %ld\n",strlen(str)); //8
printf("sizeof(str)= %ld\n",sizeof(str)); //8

cp=strcpy(buff,name);
printf("buff= %s\n",buff);


}
