#include<stdio.h>
struct data{
int year;
char gender;
};
struct data *function(struct data *var1);
int main()
{
	struct data var3;
	struct data *var;
	var=function(&var3);
	printf("OUTPUT= %d  %c",var->year,var->gender);
return 0;
}


struct data *function(struct data *var1)
{
	
	var1->year=2023;
	var1->gender='m';
	return var1;
}

