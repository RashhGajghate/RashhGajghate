#include<stdio.h>
//#define SIZE 5
void display(int *);
int main()
{
int arr[5]={10,20,30,40,50};
display(arr);
return 0;
}

void display(int *b)
{
	printf("b= %u\n",b);
	printf("*b= %u\n",*b);
	printf("(b+1)= %u\n",(b+1));
	printf("*(b+1)= %u\n",*(b+1));
        printf("(b+2)= %u\n",(b+2));

        printf("*(b+2)= %u\n",*(b+2));
        printf("(b+3)= %u\n",(b+3));
        printf("*(b+3)= %u\n",*(b+3));
        printf("(b+4)= %u\n",(b+4));
	printf("*(b+4)= %u\n",*(b+4));

	printf("(b+5)= %u\n",(b+5));
	printf("*(b+5)= %u\n",*(b+5));

	printf("(b+6)= %u\n",(b+6));
	printf("*(b+6)= %u\n",*(b+6));
}
