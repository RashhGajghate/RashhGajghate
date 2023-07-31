#include<stdio.h>
int main(){
	char str[]="192.168.10.7";
	char *token=strtok(str,".");
	while(token != NULL)
	{
		printf("%s\n",token);
		token=strtok(NULL,".");
	}
}
