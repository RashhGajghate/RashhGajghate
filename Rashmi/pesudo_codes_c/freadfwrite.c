#include<stdio.h>
size_t fread(void *ptr,size_t size,size_t nmemb,FILE *stream);
size_t write(const void *ptr,size_t size,size_t nmemb,FILE *stream);

int main()
{
	char buf[30];
	int buf1[20];
	fread(buf,1,10,stdin);
	fwrite(buf,1,10,stdout);
	fread(buf1,4,5,stdin);
	fwrite(buf1,4,5,stdout);
}
