#include<stdio.h>
int main()
{
	char *s2="ABCDEF";
	s2="x";
	printf("s2= %s\n",s2);
	s2++;
	printf("s2= %s\n",s2);
	
	//s2="New string";
	//printf("s2= %s\n",s2);
	//printf("sizeof(s2)= %d\n",sizeof(s2));
	return 0;
}
