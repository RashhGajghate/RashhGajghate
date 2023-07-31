#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct reg{
	char *name;
	int age;
	char gender;
	char *city;
	int pincode;
	char status[10];
	int salary;
};

int main()
{
struct reg v;
struct reg *ptr1=&v;

(ptr1->name)=(char *)malloc(sizeof(char));
(ptr1->city)=(char *)malloc(sizeof(char));

printf("sizeof(v)= %d\n",sizeof(v));
printf("sizeof(name)= %d\n",sizeof(ptr1->name));
printf("sizeof(city)= %d\n",sizeof(ptr1->city));
printf("sizeof(age)= %d\n",sizeof(v.age));
printf("sizeof(gender)= %d\n",sizeof(v.gender));
printf("sizeof(pincode)= %d\n",sizeof(v.pincode));
printf("sizeof(status)= %d\n",sizeof(v.status));
printf("sizeof(salary)= %d\n",sizeof(v.salary));


printf("Enter the detail for registration NAME,AGE,GENDER,CITY,PINCODE,MARITAL STATUS ans SALARY: ");
scanf("%s %d %c %s %d %s %d",ptr1->name,&v.age,&v.gender,ptr1->city,&v.pincode,v.status,&v.salary);
printf("\n");
printf("The registered detail: \n");
printf(" %s\n %d\n %c\n %s\n %d\n %s\n %d\n",ptr1->name,v.age,v.gender,ptr1->city,v.pincode,v.status,v.salary);

return 0;
}
