#include<stdio.h>

void char_count(char arr[]);
void remove_digits(char arr[]);

int main(){
char arr[20];
printf("Enter a string: ");
scanf("%[^\n]s",arr);
remove_digits(arr);
char_count(arr);
word_count(arr);
return 0;
}

void remove_digits(char b[])
{
char temp[20];
int i=0;
while(*b!='\0'){
if(*b==" " || *b>='a' && *b<='z' || *b>='A' && *b<='Z')
{
     *(temp+i)=*b;
     i++;
}

*b++;
}
printf("New string: %s\n",temp);
}

void char_count(char b[])
{
	int i=0;
	while(*b!='\0')
	{
		if(*b>='a' && *b<='z' || *b>='A' && *b<='Z'){
               	i++;
		}
		*b++;
	}
	printf("Char count= %d\n",i);
}






