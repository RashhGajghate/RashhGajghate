#include<stdio.h>

struct reg{
	char name[20];
	int age;
	char gender;
	char city[10];
	int pincode;
	char status[10];
	int salary;
};

int main()
{

struct reg v;
printf("Enter the detail for registration NAME,AGE,GENDER,CITY,PINCODE,MARITAL STATUS ans SALARY: ");
scanf("%s %d %c %s %d %s %d",&v.name,&v.age,&v.gender,&v.city,&v.pincode,&v.status,&v.salary);
printf("\n");
printf("The registered detail: \n");
printf(" %s\n %d\n %c\n %s\n %d\n %s\n %d\n",v.name,v.age,v.gender,v.city,v.pincode,v.status,v.salary);

return 0;

}