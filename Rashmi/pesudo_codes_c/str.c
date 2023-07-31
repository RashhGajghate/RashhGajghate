#include<stdio.h>
#include<string.h>
int main()
{
	char name[10];
	char buff[20];

	strcpy(name,"rashh me");
	printf("name= %s\n",name);

	strcpy(buff,name);
	printf("buff= %s\n",buff);


	strcat(buff,"1506");
	printf("buff= %s\n",buff);

printf("%d\n",strcmp(buff,name));


}
