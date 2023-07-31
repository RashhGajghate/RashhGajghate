#include<stdio.h>

struct student{
	char name[20];
	int rollno;
	int submarks[4];
};

int main()
{
	int i,j;
	struct student arr[3];
         
	for(i=0;i<3;i++)
	{
		printf("Enter data for student %d\n\n",i+1);
		printf("Enter name: ");
		scanf("%s",arr[i].name);

		printf("Enter rollno: ");
		scanf("%d",&arr[i].rollno);

		for(j=0;j<4;j++)
		{
			printf("Enter marks for subject %d=",j+1);
			scanf("%d",&arr[i].submarks[j]);
		}
	}

      
	for(i=0;i<3;i++)
	{
		printf("Data of student %d\n",i+1);
		printf("Name:%s, Rollno: %d,Marks:",arr[i].name,arr[i].rollno);

		for(j=0;j<4;j++)
	        printf("%d ",arr[i].submarks[j]);
		printf("\n");
	}




return 0;
}
