#include<stdio.h>
#define SIZE 5
void display(int *);
int main()
{
	int arr[SIZE]={10,20,30,40,50};
	display(arr);
	return 0;
}

void display(int *b)
{

	printf("b= %p\n",b);
	printf("*b= %d\n",*b);
	printf("*b+1= %d\n",*(b+1));
	for(int i=0;i<SIZE;i++)
	
	{
		printf("*b[i]=%d\n",*(b+i));
	}
	printf("\n");

}
