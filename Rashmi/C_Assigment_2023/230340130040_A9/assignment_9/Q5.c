#include<stdio.h>

struct reg{
	char name[20];
	int age;
	char gender[20];
	char city[20];
	int pincode;
	char status[10];
	int salary;
};


int main()
{
	struct reg v;

	printf("Enter the details as NAME,AGE,GENDER,CITY,PINCODE,MARITAL STATUS,SALARY for registration: ");
	scanf("%s %d %s %s %d %s %d",&v.name,&v.age,&v.gender,&v.city,&v.pincode,&v.status,&v.salary);
	printf("The registration: ");
	printf("\n");
	printf(" NAME=%s\n AGE=%d\n GENDER=%s\n CITY=%s\n PINCODE=%d\n MARITIAL STATUS=%s\n SALARY=%d\n",v.name,v.age,v.gender,v.city,v.pincode,v.status,v.salary);
	return 0;
}
