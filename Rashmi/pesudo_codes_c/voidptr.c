#include<stdio.h>
void main()
{    
	int x;
	char ch;


	void *vp;
	vp=&x;
	vp=&ch;
	//vp=&arr;
//	printf("%p\n",vp+1);
     //	printf("%u\n",*vp);

	printf("%p\n",(int *)vp+1);
	printf("%d\n",*(int *)vp);

}
