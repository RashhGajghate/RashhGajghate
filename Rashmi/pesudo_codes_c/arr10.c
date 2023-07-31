#include<stdio.h>
#define SIZE 5
void display(int []);
int main()
{
int arr[SIZE]={10,20,30,40,50};
display(arr[]);
return 0;
}

void display(int arr[])
{
	for(int i=0;i<SIZE;i++)
		printf("%d\n",arr[i]);

}
