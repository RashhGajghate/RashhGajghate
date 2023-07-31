#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

int count=0;

struct patient{
	char name[20];
	char gender;
	long int mobile;
	int pid;
	char dname[20];
}var[10];

void add(struct patient []);
void display(struct patient []);
void search(struct patient []);
void modify(struct patient []);

int main(){
	int choice;
	
	while(1){
		printf("1:Add New Patient\n2: Search Patient:\n3: Display All Patients Info\n4:Modify\n5: Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				add(var);
				break;
			case 2:
				search(var);
				break;
			case 3:
				display(var);
				break;
			case 4:
				modify(var);
				break;
			case 5:	
				exit(0);
				break;
	
		}
	}
}


void add(struct patient var[10]){

	
	
	
	
	printf("Enter the name\n");
	scanf("%s[^\n]s", var[count].name);
	printf("Enter the mobile no\n");
	scanf("%ld", &var[count].mobile);
	__fpurge(stdin);
	printf("Enter the gender\n");
	scanf("%c", &var[count].gender);
	printf("Enter the ID\n");
	scanf("%d", &var[count].pid);
	printf("Enter the Dr.Name\n");
	scanf("%s[^\n]s", var[count].dname);
	
	
	count++;
}


void display(struct patient var[10]){
	for(int i=0;i<count;i++){
		printf("\n\n******* Output for %d \n ",i+1);
		printf("Name =%s\n",var[i].name);
		printf("Mobile number =%ld\n",var[i].mobile);
		__fpurge(stdin);
		printf("Gender =%c\n",var[i].gender);
		printf("PID=%d\n",var[i].pid);
		printf("Doctor Name =%s\n",var[i].dname);	
		}
	}	


void search(struct patient var[10]){
	int search1;

	printf("\nEnter the number you want to serach\n");
	scanf("%d",&search1);
	for(int i=0;i<count;i++){	
	if(var[i].pid==search1){			
		printf("Present \n\n");
		break;
	}
	
   }
  } 


void modify(struct patient var[10]){	
	int search1;
	printf("\nEnter the number you want to serach");
	scanf("%d",&search1);
	for(int i=0;i<count;i++){	
	if(var[i].pid==search1){	
		printf("Enter the name\n");
		scanf("%s[^\n]s", var[i].name);
		printf("Enter the mobile no\n");
		scanf("%ld", &var[i].mobile);
		printf("Enter the gender\n");
		scanf("%c", &var[i].gender);
		printf("Enter the ID\n");
		scanf("%d", &var[i].pid);
		printf("Enter the Dr.Name\n");
		scanf("%s[^\n]s", var[i].dname);}
		
		}
	}
	
