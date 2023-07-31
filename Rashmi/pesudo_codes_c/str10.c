#include<stdio.h>
int main()
{
	char a[]="cdac-acts";
	char *b="cdac-acts";

	printf("%d %d\n",sizeof(a),sizeof(b));
	printf("%d %d\n",sizeof(*a),sizeof(*b));
}
