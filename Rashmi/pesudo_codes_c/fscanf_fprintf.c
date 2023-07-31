#include<stdio.h>
int fscanf(FILE *stream, const char *formate,...);
int fprintf(FILE *stream,const char *formate,...);
int main()
{
int x;
char ch;
fscanf(stdin,"%d %c",&x,&ch);
fprintf(stdout,"%d %c\n",x,ch);
}
