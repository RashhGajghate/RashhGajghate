#include<stdio.h>

struct class{
	int std;
	char div;
	union stu{
		int rollno;
	}s;
};


int main()
{       

	struct class var={5,'B',20};

        printf("Enter the Standard and division: ");
	scanf("%d %c",&var.std,&var.div);

        printf("Enter the rollno: ");
	scanf("%d",&var.s.rollno);

	printf("The student is in %d standard and %c division\n",var.std,var.div);
	printf("The rollno of the student is %d\n",var.s.rollno);

       printf("sizeof(var)= %d\n",sizeof(var));
       printf("sizeof(stu)= %d\n",sizeof(var.s));

	return 0;
}
