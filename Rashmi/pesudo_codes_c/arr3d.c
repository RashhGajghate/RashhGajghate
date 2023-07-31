#include<stdio.h>
int main()
{
	int a[2][3][4]={{1,2,3,4,	
                        4,3,2,1,   
                        7,8,9,0} ,
	      {1,2,3,4,
	      4,3,2,1,
              7,8,9,0}	      
	      
	         
	};
	printf("\n%u \n%u \n%u \n%u",a,*a,**a,***a);
}
