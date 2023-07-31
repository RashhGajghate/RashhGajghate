#include<stdio.h>
struct student{
	char name[20];
	int rollno;
	float marks;
};

int main()
{
struct student s1;
struct student s2;
printf("Enter the name,rollno and marks: ");
scanf("%s %d %f",&s1.name,&s1.rollno,&s1.marks);
printf("Student1= %s %d %f\n",s1.name,s1.rollno,s1.marks);
s2=s1;
printf("Student2= %s %d %f\n",s2.name,s2.rollno,s2.marks);
return 0;
}
