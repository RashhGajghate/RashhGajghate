#include<stdio.h>
int main()
{
	typedef int myint;
	myint a=10,b=20;
	printf("Sizeof(myint)= %ld\n",sizeof(myint));


	typedef float myfloat;
	myfloat d=12.34,c=34.56;
	printf("Sizeof(myfloat) =%ld\n",sizeof(myfloat));


	typedef int* ptr;

	ptr aptr;
	printf("sizeof(aptr)= %ld\n",sizeof(aptr));
}
