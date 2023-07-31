#include<stdio.h>
int sscanf(const char *str,const char * format,...);
int sprintf(char *str,const char * format,...);
int main()
{
	char *input="HELLO 100 3.5";
	char outstr[30];
	char str[10];int i;float f;
	sscanf(input,"%s %d %f",str,&i,&f);
	printf("%s %d %f\n",str,i,f);
	//sprintf(outstr,"OUTSTR= %f %d %s",f,i,str);
	sprintf(outstr,"%f",f);
	puts(outstr);
}
