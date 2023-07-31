#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **pt = (int*)malloc(sizeof(int*) * 4);
		for(int i=0;i<4;i++)
		{
			scanf("%d",pt[i]);
		}
		for(int i=0;i<4;i++)
		{
			printf("%d\n",*pt[i]);
		}
		 for(int i=0;i<4;i++)
		 	free(pt[i]);
		 free(pt);
}
