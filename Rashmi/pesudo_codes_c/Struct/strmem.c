#include<stdio.h>
#include<string.h>

struct student{
	char name[20];
	int rollno;
	float marks;
};


int main()
{
	//struct student s1={"Marry",20,90};
	//printf("Displaying the value: %s %d %f",s1.name,s1.rollno,s1.marks);


	//struct student s2;
	//strcpy(s2.name,"JOHN");
	//s2.rollno=26;
	//s2.marks=60;

	//printf("Displaying the values: %s %d %f",s2.name,s2.rollno,s2.marks);


	struct student s3;
	printf("Enter name, rollno and marks: ");
	scanf("%s %d %f",&s3.name,&s3.rollno,&s3.marks);
        printf("Displaying the values: %s %d %f",s3.name,s3.rollno,s3.marks);


return 0;


}
