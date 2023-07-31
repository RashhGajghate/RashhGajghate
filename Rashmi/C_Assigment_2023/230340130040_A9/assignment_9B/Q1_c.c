#include<stdio.h>
int main()
{
	union output{
        	union input{
		 int num;	 
		}in;
	}out;

        out.in.num=10; 
	printf("The value of num=%d\n",out.in.num);
	
	return 0;

}
