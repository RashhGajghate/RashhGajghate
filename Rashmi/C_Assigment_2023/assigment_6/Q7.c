#include<stdio.h>
int main(){

	int arr[5]={10,20,30,40,50};
	int (*parr)[5];
	parr=&arr;

	printf("sizeof(parr)          = %d\n",sizeof(parr));
	printf("sizeof(*parr)         = %d\n",sizeof(*parr));
	printf("sizeof(**parr)        = %d\n",sizeof(**parr));
	printf("parr                  = %p\n",parr);
	printf("*parr                 = %d\n",**parr);
	printf("*(parr+1)             = %d\n",**(parr+1));
	printf("*(parr+2)             = %d\n",**(parr+2));
	printf("*(parr+3)             = %d\n",**(parr+3));
	printf("*(parr+4)             = %d\n",**(parr+4));
	return 0;
}
