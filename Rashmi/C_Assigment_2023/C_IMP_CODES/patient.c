#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

struct patient{
	char name[50];
	char gender;
	long int mobile;
	int pid;
	char doctor_name[50];
}var[10];

int count=0;

void add(struct patient var[]);
void search(struct patient var[]);
void display(struct patient var[]);
void modify(struct patient var[]);

int main()
{
	while(1){
		int choice;
		printf("\n**Patient Portal**\n");
		printf("1. Add Patient\n");
		printf("2. Search Patient\n");
		printf("3. Display All Patients\n");
		printf("4. Modify\n");
		printf("0. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice){
			case 1: add(var);
				printf("Patient successfully added.");
				break;
			case 2: search(var);
				break;
			case 3: display(var);
				break;
			case 4: modify(var);
				printf("Modification successsful");
				break;
			case 0: exit(0);

			default : printf("Invalid input.");
				  break;
		}
	}
	return 0;
}
void add(struct patient var[])
{
	printf("Enter name:");
	scanf("%s[\n]s",var[count].name);
	__fpurge(stdin);
	printf("Enter gender(m/f):");
	scanf("%c",&var[count].gender);
	printf("Enter mobile no.:");
	scanf("%ld",&var[count].mobile);
	printf("Enter patient id:");
	scanf("%d",&var[count].pid);
	printf("Enter doctor's name:");
	scanf("%s[^\n]s",var[count].doctor_name);
	count++;
}
void search(struct patient var[])
{
	int search;
	printf("Enter patient id:");
	scanf("%d",&search);
	for(int i; i<count; i++){
		if(search==var[i].pid){
			printf("Patient found.");
			printf("Patient's name:%s[^\n]s",var[i].name);
			printf("Gender:%c",var[i].gender);
			printf("Mobile no.:%ld",var[i].mobile);
			printf("Patient's id:%d",var[i].pid);
			printf("Doctor's name:%s[^\n]s",var[i].doctor_name);
		}
	}
}
void display(struct patient var[]){
	printf("List of Patients");
	for(int i; i<count; i++){
			printf("Patient found.");
			printf("Patient's name:%s[^\n]s",var[i].name);
			printf("Gender:%c",var[i].gender);
			printf("Mobile no.:%ld",var[i].mobile);
			printf("Patient's id:%d",var[i].pid);
			printf("Doctor's name:%s[^\n]s",var[i].doctor_name);
	}
}
void modify(struct patient var[]){

	char modify;
	__fpurge(stdin);
	printf("Enter patient id:");
	scanf("%c",&modify);
	for(int i; i<count; i++){
		if(modify==var[i].pid){
			printf("Patient found.");
			printf("Patient's name:%s[^\n]s",var[i].name);
			printf("Gender:%c",var[i].gender);
			printf("Mobile no.:%ld",var[i].mobile);
			printf("Patient's id:%d",var[i].pid);
			printf("Doctor's name:%s[^\n]s",var[i].doctor_name);
		}
	}
}
	
