#include<stdio.h>
struct data{
	int year;
};
struct data function(struct data);

int main()
{
struct data var={2023};
	function(var);
printf("OUTPUT= %d",var.year);
}

struct data function(struct data var1)
{      
        
	return var1;
}
