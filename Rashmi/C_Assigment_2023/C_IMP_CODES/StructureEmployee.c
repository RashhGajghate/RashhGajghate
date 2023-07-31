#include<stdio.h>
#include <stdio_ext.h>

union IdProofs{
	long int adhar;
	long int passport;
	long int voterId;
 }id;
	
struct employe{
	int empid;
	char name[20];
	int salary;
	int yoj;
        char gender;
        int age;
        union IdProofs var1;
 }emp[2];
 
 void total(struct employe emp[], int);
  void average(struct employe emp[], int);
 void max_salary(struct employe emp[], int); 
  void min_salary(struct employe emp[], int);
//void max_Service(struct employe emp[], int);  
 
 int main(){
 	int exit,choice,i=0,choice1;
 
 	while(1){
 	
 	       
 	   printf("Enter the name of candidate");
 	   scanf  ("%s",emp[i].name);
 	   
 	   printf("Enter the Salary of candidate");
 	   scanf  ("%d",&emp[i].salary);
 	   
 	   printf("Enter the year of joining of candidate");
 	   scanf  ("%d",&emp[i].yoj);
 	   
 	   printf("Enter the Employee ID of candidate");
 	   scanf  ("%d",&emp[i].empid);
 	   
 	   __fpurge(stdin);
 	   printf("Enter the gender of candidate");
 	   scanf  ("%c",&emp[i].gender);
 	   
 	   printf("Enter the age of candidate");
 	   scanf  ("%d",&emp[i].age);
 	  
 	   printf("Enter 1.AADHAR 2.Passport 3.VOTER 4.Other:");
	   scanf("%d",&choice);
	   printf("Enter id number:");
	   
	   
	   
	   
	   switch(choice){
	   
	   case 1: 
	  	printf("Enter the Adhaar Card No.");
	   	scanf("%ld" ,&emp[i].var1.adhar);
	   	break;

	   	
	    case 2: 
	  	printf("Enter the Passport  No.");
	   	scanf("%ld" ,&emp[i].var1.passport);
	   	break;
	   	
	   case 3: 
	  	printf("Enter the VoterId  No.");
	   	scanf("%ld" ,&emp[i].var1.voterId);
	   	break;
	   	
	   default: 
	  	printf("Enter the Adhaar  No.");
	   	scanf("%ld" ,&emp[i].var1.adhar);
	   	break;
 	   }
 	   
 	   printf("Enter 0 for EXIT \n Enter 1 for MORE\n");
 	   scanf("%d" , &exit);
 	   
 	   __fpurge(stdin);
 	   if (exit==1){
 	   	i++;
 	   	}
 	   else{
 	   	break;
 	   	}
 	}   
 	   
 	printf("Total Employe:%d\n",i+1);
 	
 	total(emp,i);
 	average(emp,i);
	max_salary(emp,i); 	
 	min_salary(emp,i);
 //	max_service(emp,i);
 /*	
 	printf("Enter 1: Total Salary\n2: Average Salary\n3: Max. Salary\n4: Min. Salary\n5: Employees with maximum Service\n6: Employees with minimum Service\n ");

	switch(choice1){
			case 1:
				total(emp,i);
				break;

			case 2:
				average(emp,i);
				break;

			case 3:
				max_salary(emp,i);
				break;
		max_Service	case 4:
				min_salary(emp,i);
				break;

			case 5:
	int main(){			max_service(emp,i);
				break;

			case 6:
				min_service(emp,i);
				break;
			
			default:
				printf("Invalid input\n");
				break;
				
	}
0*/
	return 0;
	
}


void total(struct employe emp[], int i)
{

	int sal=0;
	for(int k=0;k<=i;k++)
	{	
		sal=sal+emp[i].salary;
		}
	printf("Total Salary %d\n", sal);	
}
	
void average(struct employe emp[], int i)
{
	printf("%d",i);
	int sal=0;
	for(int k=0;k<=i;k++)
	{	
		sal=sal+emp[i].salary;
		}
	int avg=0;
	avg=(sal)/(i);
	printf("Average Salary %d\n", avg);	
}

void max_salary(struct employe emp[], int i)
{
	int highest,e;
	highest=emp[0].salary;
	if(emp[i].salary>highest)
        {
            highest=emp[i].salary;
           e=emp[i].salary;
        }
        else{
        	i=0;
        	e=emp[i].salary;
        }
        printf("Max salary=%d\n",emp[i].salary);
  }
  
void min_salary(struct employe emp[], int i)
{
	int lowest,e;
	lowest=emp[0].salary;
	for(int n=0;n<=i;n++){
	if(emp[i].salary<lowest)
        {
            lowest=emp[i].salary;
           e=emp[i].salary;
        }
        else{
        	i=0;
        	e=emp[i].salary;
        }
        printf("Min salary=%d\n",emp[i].salary);
        }
        
  } 
 /* 	
void max_Service(struct employe emp[], int i)
{
	int lowest,e;
	lowest=emp[0].salary;
	for(int n=0;n<=i;n++){
	if(emp[i].salary<lowest)
        {
            lowest=emp[i].salary;
           e=emp[i].salary;
        }
        else{
        	i=0;
        	e=emp[i].salary;
        }
        printf("Min salary=%d\n",emp[i].salary);
        }
        
  } 
  */
