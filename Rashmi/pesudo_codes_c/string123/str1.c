#include<stdio.h>

int main()
{
char s1[]="abcdef";
s1[0]='W';
printf("%s\n",s1);
//s1++;
//printf(s1);
s1="New String";
printf(s1);
printf("sizeof(s1)= %d\n",sizeof(s1));
return 0;
}
