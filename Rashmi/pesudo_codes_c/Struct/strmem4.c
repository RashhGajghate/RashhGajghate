#include<stdio.h>

struct student{
	char name[20];
	int rollno;
};

int main()
{
struct student v[5];
for(int i=0;i<5;i++)
{
	printf("Enter name and marks: ");
	scanf("%s %d",v[i].name,&v[i].rollno);
}

for(int i=0;i<5;i++)
printf("The students data= %s %d\n",v[i].name,v[i].rollno);
return 0;
}
