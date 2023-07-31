#include<stdio.h>
int main()
{
	char names[5][40];
	for(int i=0;i<5;i++)
	{
		printf("Enter %d string\n",i+1);
		__fpurge(stdin);
		scanf("%[^\n]s",names[i]);
	}

	for(int i=0;i<5;i++)
	{
		printf("String %d= %s\n",i+1,names[i]);
	}
	return 0;
}
