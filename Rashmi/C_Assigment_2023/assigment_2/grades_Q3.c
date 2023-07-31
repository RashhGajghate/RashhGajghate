#include<stdio.h>
void main()
{
	int hin,eng,maths,sci,his,sum=0,per=0,grade=1;
	printf("Enter the marks for HINDI ENGLISH MATHS SCIENCE HISTORY : ");
	scanf("%d%d%d%d%d",&hin,&eng,&maths,&sci,&his);
	sum=eng+hin+his+sci+maths;
	per=sum*100;
	grade=per/500;  

	printf("Sum= %d\n",sum);
	printf("Percentage= %d\n",grade);

	if(grade>=75)
	{
		printf("Grade A\n");
	}
	else if(grade<75 && grade>=65)
	{
		printf("Grade B\n");
	}
	else if(grade<65 && grade>=55)
	{
		printf("Grade C\n");
	}
	else
	{
		printf("Fail \n");
	}
}
