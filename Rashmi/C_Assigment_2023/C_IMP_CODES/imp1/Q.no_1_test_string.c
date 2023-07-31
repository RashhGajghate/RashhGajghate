#include<stdio.h>
  #include<string.h>
#include<stdio_ext.h>
#include<stdlib.h>


#define MAX 100

int function_select(void);
void remove_digit_symbol(char*);
void word_char_count(char*);
void remove_space_tab_newline(char*);

int main()
{
	int choice;
	char string[MAX];
	char *string_p;
	string_p = string;
	
	while(1)
	{
		choice=function_select();
	
		switch(choice)
		{
			case 1:
				printf("Enter the String:- \n");
				__fpurge(stdin);
				scanf("%[^\n]s", string);
				remove_digit_symbol(string_p);
				break;
	
			case 2:
				printf("Enter the String:- \n");
				__fpurge(stdin);
				scanf("%[^\n]s", string);
				word_char_count(string_p);
				break;
			
			case 3:
				printf("Enter the String:- \n");
				printf("press ctrl + V then Ctrl + M for termination :- \n");
				__fpurge(stdin);
				scanf("%[^\r]s", string);
				remove_space_tab_newline(string_p);
				break;
			case 4:
				printf("Thankyou !!\n");
				exit(1);

			default :
				printf("Wrong choice !! enter again:- \n");
		}
	}

return 0;
}

int function_select(void)
{
	int choice;
	printf("****************************************************\n");
	printf("1 for remove the digit and symbols:- \n");
	printf("2 for word count char count :- \n");
	printf("3 for conversion of non space string:- \n");
	printf("4 for for exit :- \n");
	printf("****************************************************\n");
	printf("Enter the choice:- \n");
	scanf("%d", &choice);

return choice;
}

void remove_digit_symbol(char *str)
{
	int len, j=0;
	char temp[MAX];
	len=strlen(str);

	for(int i=0; i <=len; i++)
	{
		if((*(str+i) >= 'A' && *(str+i) <= 'Z') || (*(str+i) >= 'a' && *(str+i) <= 'z'))
		{
			temp[j]=*(str+i);
			j++;
		}
	}
	temp[j]='\0';

	printf("string without digits and symbols :- %s\n",temp);
}


void word_char_count(char *str )
{
	int len, w_count=1, c_count=0;
	len=strlen(str);

	for(int i=0; i <=len; i++)
	{
		if(*(str+i) ==' ' && *(str+(i+1)) !=' ')
		{
			w_count++;
		}
	}
              	printf("No of words in given string is %d\n", w_count);

	for(int i=0; i <=len; i++)
	{
		if(*(str+i)==(' ') || *(str+i)=='\n' || *(str+i)=='\0')
			continue;
		c_count++;
	}
	printf("No of alphabate in given string is %d\n", c_count);

}
void remove_space_tab_newline(char *str)
{
	int j=0, len;
	char temp[MAX];
	len=strlen(str);

	for(int i=0; i <=len; i++)
	{
		if(*(str+i) == ' ' || *(str+i)== '\t' || *(str+i)=='\n')
			continue;
		temp[j]=*(str+i);
		j++;
	}
	printf("string without space, tab and newline :- %s\n", temp);


}
