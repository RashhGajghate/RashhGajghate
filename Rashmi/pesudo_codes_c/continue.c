#include<stdio.h>

int main()
{
	for(int i=1;i<11;i++){
		if(i == 4){
			break;
		}
		printf("Number : %d\n",i);
	}
	printf("\\n");
	return 0;
}
