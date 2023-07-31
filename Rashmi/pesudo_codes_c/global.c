#include<stdio.h>
int i_value=100;
 int main()
{      
	void fun(void);
	printf("%d\n",i_value);
	i_value=50;
	printf("%d\n",i_value);
	fun();
	printf("%d\n",i_value);
}
void fun()
{      
	
	i_value=25;
	printf("%d\n",i_value);
}

