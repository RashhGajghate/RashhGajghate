#include<stdio.h>

struct data
{
	char ch;
	int i;
	float f;

};


int main()
{
struct data var={'c',100,12.55};
f(&var);
g(var);
}

f(struct data *r)
{
	printf("%c %d %f",r->ch,r->i,r->f);
}

g(struct data r)
{
	printf("%c %d %f",r.ch,r.i,r.f);
}
