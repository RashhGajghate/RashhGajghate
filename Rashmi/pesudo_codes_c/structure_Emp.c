#include<stdio.h>
#include <stdlib.h>

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

void display_emp_info(struct employee *);
void add_emp_info(struct employee *,int);
void search_info(struct employee *);

int count=0;
int main(){
   struct employee emp[3];  
   int id;
   while(1){
   	printf("1->add emp info\n2->display emp info\n3->Search info\n4->Modify info\n5->exit\n");
   	int ch,id1;
   	scanf("%d",&ch);
	switch(ch){
	   	case 1: add_emp_info(emp+count,0);
	   		count++;
	   		break;
	   	case 2: display_emp_info(emp);
	   		break;
		case 3: search_info(emp);	
			break;
		case 4:printf("Enter Employee ID: ");
		       scanf("%d",&id1);
		       for(int i=0;i<count;i++){
		       if(id1==emp[i].empid)
		       add_emp_info(emp,id1);}
		       printf("Employee ID is not found to be modify\n\n");
		       break;
	   	case 5: exit(0);
	   		break;
	   }
   }
 return 0;
}

void add_emp_info(struct employee *p,int id){
   if(id==0){
   printf("-----Enter the employee details: -----\n");
   printf("Enter Employee ID : ");  
   scanf("%d",&p->empid); }
   printf("Enter Employee Name : ");
   scanf("%s",p->name);
   printf("Enter Employee gender : ");
   scanf("%*c%c",&p->gen);
   printf("Enter Employee age : ");
   scanf("%d",&p->age);
   
   label:
   printf("Enter your choice for ID proof \n1-Adhar card\n2-Passport\n3-Voter ID\n");
   int a;
   scanf("%d",&a);
      switch(a){
	    case 1: printf("Enter your Adhar_no. :");
		    scanf("%d",&p->id.adhar);
		    break;
	    case 2: printf("Enter your Passport_no. :");
		    scanf("%d",&p->id.pass);
		    break;
	    case 3: printf("Enter your Voter_Id. :");
		    scanf("%d",&p->id.voter);
		    break;
           default:
                   printf("Please enter select appropriate choice :-\n");
                   goto label;
		    
	}
   printf("Enter Year of joining: ");
   scanf("%d",&p->yr_join);
   printf("Enter emp salary: ");
   scanf("%d",&p->sal);
}


void display_emp_info(struct employee *p){
   for(int i=0;i<count;i++){	
   printf("--------- Details of Employee -------\n");
   printf("Employee ID :              %d\n",(p+i)->empid);
   printf("Employee Name :            %s\n",(p+i)->name);
   printf("Employee gender :          %c\n",(p+i)->gen);
   printf("Employee age :             %d\n",(p+i)->age);
   printf("Employee ID proof :        %d\n",(p+i)->id.adhar);
   printf("Employee Year of joining : %d\n",(p+i)->yr_join);
   printf("Employee salary :          %d\n",(p+i)->sal);
   printf("\n");
   }
   
}	

 void search_info(struct employee *p){
        int id;
        printf("Enter the Employee ID: ");
        scanf("%d",&id);
        printf("-------The searched employee details--------\n");
        for(int i=0;i<count;i++){
                if(id==(p+i)->empid)
                {
                  printf("Employee ID :              %d\n",(p+i)->empid);
                  printf("Employee Name :            %s\n",(p+i)->name);
                  printf("Employee gender :          %c\n",(p+i)->gen);
                  printf("Employee age :             %d\n",(p+i)->age);
                  printf("Employee ID proof :        %d\n",(p+i)->id.adhar);
                  printf("Employee Year of joining : %d\n",(p+i)->yr_join);
                  printf("Employee salary :          %d\n",(p+i)->sal);
                  printf("\n");        
                  return;
               }
	}
          printf("Employee ID does not found to be searched\n\n");
}





















