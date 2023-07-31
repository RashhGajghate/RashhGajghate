#include<stdio.h>
int  main()
{
	int a[5]={10,20,30,40,50};
	int a2[3][2]={{10,20},{30,40},{50,60}};
	int a3[2][3][2]={{10,20,  {70,80,
		          30,40,   90,100,
			  50,60},  110,120}};


	printf("sizeof(a)= %d\n",sizeof(a));  //20
	printf("sizeof(a2)= %d\n",sizeof(a2)); //24
	printf("sizeof(a3)= %d\n",sizeof(a3)); //48

	printf("sizeof(a[0])= %d\n",sizeof(a[0])); //4
	printf("sizeof(*a)= %d\n",sizeof(*a)); // 4

	printf("sizeof(a2[0])= %d\n",sizeof(a2[0]));  //8
	printf("sizeof(*a2)= %d\n",sizeof(*a2)); //4
	printf("sizeof(**a2)= %d\n",sizeof(**a2)); //4

	printf("sizeof(a3[0])= %d\n",sizeof(a3[0])); //24
	printf("sizeof(*a3)= %d\n",sizeof(*a3)); //8
	printf("sizeof(**a3)= %d\n",sizeof(**a3));//4
	printf("sizeof(***a3)= %d\n",sizeof(***a3)); //4




	
}
