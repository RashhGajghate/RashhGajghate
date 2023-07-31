#include<stdio.h>
int main()
{
	int i,j;
	int arr[3][4]={{10,20,30,40},{50,60,70,80},{90,100,110,120}};
	int (*p)[4]=arr;
	p=arr;

	printf("p   = %ld\n",sizeof(p));
	printf("*p  = %ld\n",sizeof(*p));
	printf("**p = %ld\n",sizeof(**p));
	printf("**p   = %d\n",(p));
	printf("p   = %p\n",p);
	printf("p+1 = %p\n",p+1);
	

	               for(i=0;i<3;i++)
		       {
			       for(j=0;j<4;j++){
			printf("arr[i][j]= %p\n",arr[i][j]);
			printf("(*(p+i))[j]= %d\n",(*(p+i))[j]);
			printf("*(*(p+i)+j)= %d\n",*(*(p+i)+j));
			printf("\n");
		       }
		       }
		       return 0;
}
