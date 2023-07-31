#include<stdio.h>
int main()
{
	char alp;
	printf("Enter a alphabet: ");
	scanf("%c",&alp);
	if(alp=='a' || alp=='e' || alp== 'i' || alp=='o' || alp== 'u')
	{
		printf("The given alphabet is vowel\n");
	}
	else
	{
		printf("The given alphabet is consonant\n");
	}
}
