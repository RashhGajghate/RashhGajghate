#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

#define NUM_MAX_BOOK 100
#define NAME_MAX_BOOK 50

typedef struct book
{
	char b_author[NAME_MAX_BOOK];
	char b_title[NAME_MAX_BOOK];
	char b_type[NAME_MAX_BOOK];
	char b_isbn[15];
	int b_id;
}book_t;


int function_select(void);
void add_new_book(book_t*, int);
//void display__book(book_t*, int);
void display_book(book_t*, int);
void search_book(book_t*, int, int);


int main()
{
	int choice, id, book_num=0;

	book_t e_book_lib[NUM_MAX_BOOK];

	
	while(1)
	{
		choice=function_select();
		switch(choice)
		{

			case 1:
				add_new_book(e_book_lib, book_num);
				book_num++;
				break;
			case 2:
				if (book_num==0)
				{
					printf("NO books available !!!\n");
					printf("plese add some books\n");
				}
				for(int i=0; i<book_num; i++)
					display_book(e_book_lib, i);
				break;
			case 3:
				printf("Enter book id for search: -");
				scanf("%d", &id);
				search_book(e_book_lib, book_num, id);
				break;
			case 4:
				printf("Thankyou !!\n");
				exit(0);
				break;
			default:
				printf("Sorry !!! Wrong choice !! try again !!\n");
				break;
		}
	}
return 0;
}

int function_select(void)
{
	int choice;
	printf("*************************************************\n");
	printf("enter 1 for add new book:- \n");
	printf("enter 2 for display all book info:- \n");
	printf("enter 3 for searching book :- \n");
	printf("enter 4 for Exit :- \n");
	printf("*************************************************\n");
	printf("Enter your choice :- \n");
	scanf("%d", &choice);

return choice;
}
        
void add_new_book(book_t *bn, int b_num)
{
	int flag=0;
	if(b_num >= NUM_MAX_BOOK)
	{
		printf("Sorry!!!, no more space\n");
		exit(1);
	}
	printf("Enter the book details:- \n");
	printf("Enter author name:- "); 
        __fpurge(stdin);
	scanf("%s",(bn+b_num)->b_author);
        printf("Enter title name:- ");
        __fpurge(stdin);
        scanf("%s",(bn+b_num)->b_title);
        printf("Enter book type:- ");
        __fpurge(stdin);
        scanf("%s",(bn+b_num)->b_type);
        printf("Enter book isbn number:- ");
        __fpurge(stdin);
        scanf("%s",(bn+b_num)->b_isbn);
	for(int i=3; i>=0; i--)
	{
		printf("Enter book ID only 3 digits:- ");
		scanf("%d",&(bn+b_num)->b_id);
		if(((bn+b_num)->b_id)>99 && ((bn+b_num)->b_id) < 1000)
		{
			flag++;
			break;
		}
		if(i==0)
			break;
		printf("Sorry try again !!!  you have %d more chance:- \n", i);
	}
	if(flag==0)
		printf("\n***********maximum limit cross*********\n");
return;
}

void display_book(book_t *bn, int i)
{
	printf("*************************************************\n");
	printf("Details of book_%d is :- \n", i);
	printf("book title: %s \n",(bn+i)->b_title);
        printf("author name : %s\n",(bn+i)->b_author);
	printf("book type : %s\n",(bn+i)->b_type);
	printf("book id: %d\n",(bn+i)->b_id);
	printf("book isbn no: %s\n",(bn+i)->b_isbn);
	printf("*************************************************\n");
}

void search_book(book_t *bn, int b_num, int id)
{
	for(int i=0;i<b_num; i++)
	{
		if((bn+i)->b_id == id)
		{
			printf("book found at %d \n",i);			      
			display_book(bn, i);
			return;
		}
	}

	printf("Book not found !!!!!\n");
	return;
}
