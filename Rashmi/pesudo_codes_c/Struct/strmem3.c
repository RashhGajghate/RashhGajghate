#include<stdio.h>

struct student{
	char name[20];
	int rollno;
	int salary;
};


int main()
{
struct student var;
printf("Size of var= %d\n",sizeof(var));
printf("Size of student= %d\n",sizeof(struct student));
return 0;
}
