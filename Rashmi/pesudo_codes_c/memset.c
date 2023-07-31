#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *cptr;
	cptr=malloc(20);
	char *ptr;
	ptr=memset(cptr,49,19);
	printf("%s\t",cptr);
	printf("%s\t",ptr);
	free(cptr);
	return 0;
}
