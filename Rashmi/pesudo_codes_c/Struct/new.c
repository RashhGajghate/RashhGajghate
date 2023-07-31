#include<stdio.h>
union id_proof{
   int adhar;
   int pass;
   int voter;
};
struct employee{
	int empid;
	char name[20];
	int sal;
	int yr_join;
	char gen;
	int age;
	union id_proof id;
};
void display(struct employee[]);
int add(struct employee[]);
float avg(struct employee[]);
void search(struct employee[]);
void modify(struct employee[]);

int main()
{
   struct employee emp[3];
   int a,mod,ret=0;
   float ret2=0;
   printf("\n");
   printf("Enter the employee details: ");
   printf("Enter Employee_ID Name Salary Year_of_joining Gender Age Id_proof: ");
   printf("\n");

   for(int i=0;i<3;i++){
   start:
   printf("Enter detail for %d employee:\n",i+1);
   scanf("%d %s %d %d %c %d",&emp[i].empid,emp[i].name,&emp[i].sal,&emp[i].yr_join,&emp[i].gen,&emp[i].age);
 
   printf("Enter your choice for ID proof: 1-Adhar card  2-Passport  3-Voter ID\n");
   scanf("%d",&a);
   printf("Enter: \n");
      label:
      switch(a){
	    case 1:
		    scanf("%d",&emp[i].id.adhar);
		    break;
	    case 2:
		    scanf("%d",&emp[i].id.pass);
		    break;
	    case 3:
		    scanf("%d",&emp[i].id.voter);
		    break;
	    default:
		    printf("Enter valid input\n");
		    goto label;
      }

      printf("Do you want to modify:1-Yes 2-No  ");
      scanf("%d",&mod);
      switch(mod){
	      case 1:
		      goto start;
		      break;
	      case 2:
		      break;
      }
   }

      display(emp);
      ret=add(emp); 
      printf("Total= %d\n",ret);
      ret2=avg(emp);
      printf("Average= %f\n",ret2);
      search(emp);
      modify(emp);

 return 0;
}


void display(struct employee emp[]){
   printf("DISPLAY: \n");
   for(int i=0;i<3;i++)
   {	      
printf("\nEmployee_id: %d\nName: %s\nSalary: %d\nYear_of_joinig: %d\nGender: %c\nAge: %d\nId_proof: %ld\n",emp[i].empid,emp[i].name,emp[i].sal,emp[i].yr_join,emp[i].gen,emp[i].age,emp[i].id);
   }
}


int add(struct employee emp[]){
	int sum=0;
	for(int i=0;i<3;i++){
	 sum+=emp[i].sal;
	}
	return sum;
}

float avg(struct employee emp[]){
	int sum=0;
	float average=0;
	for(int i=0;i<3;i++){
		sum+=emp[i].sal;
		average=sum/3;
	}
	return average;
}

void search(struct employee emp[]){
	for(int i=0;i<2;i++){
		for(int j=i+1;j<3;j++){
			if(emp[i].empid==emp[j].empid)
			{ 
				printf("Employee ID is not unique\n");
			}
			else
			{
				printf("Employee ID is unique\n");
			}
		}
	}
}

void modify(struct employee emp[]){
                for(int i=0;i<2;i++)
		{
                for(int j=i+1;j<3;j++)
		{
                        if(emp[i].empid==emp[j].empid)
                        {
                                printf("Do you want to modify:1-Yes 2-No  ");
                                scanf("%d",&mod);
                               

                        }
                        else
                        {
                                printf("Employee ID is unique\n");
                        }
                }
                }

                              }





 

