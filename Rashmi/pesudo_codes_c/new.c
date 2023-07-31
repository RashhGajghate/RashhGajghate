#include<stdarg.h>
#include<stdio.h>
void fun(int arg_count,...)
{
	va_list ap;
	va_start(ap,arg_count);
	printf("%s\n",va_arg(ap,char*));
	printf("%s\n",va_arg(ap,char*));
	va_end(ap);
}

int main()
{
	int count=2;
	fun(10,"abc","xyz");
	return 0;
}

