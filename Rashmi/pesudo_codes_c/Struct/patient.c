#include<stdio.h>
#include<stdlib.h>

struct patient{
  char name[20];
  char gen;
  long mob;
  int  id;
  char doc_name[20];
};

void display_patient_details(struct patient *);
void add_patient_details(struct patient *);
void search_patient_details(struct patient *,int);

int count=0;
int main(){
	struct patient pat[3];
	int ch,id;
	while(1){
	printf(" Enter\n 1->Adding patient details\n 2->Display patient details\n 3->Search patient details\n 4->Exit\n");
	scanf("%d",&ch);
	switch(ch){
	       case 1: add_patient_details(pat+count
	       );
		       break;
	       case 2: display_patient_details(pat);
		       break;
	       case 3: printf("Enter patient ID for details: ");
		       scanf("%d",&id);  
		       search_patient_details(pat,id);
		       break;
	       case 4: exit(0); 
		       break;    
}
}
return 0;
}

void add_patient_details(struct patient *p){
count++;
int temp=0;
	printf("-------Enter Patient details--------\n");
	printf("Enter patient ID: ");
	scanf("%d",&p->id);
	printf("Enter name of patient: ");
	scanf("%s",p->name);
	printf("Enter gender of patient: ");
	scanf("%*c%c",&p->gen);
	printf("Enter mobile number: ");
	scanf("%ld",&p->mob);
	printf("Enter doctor name: ");
	scanf("%s",p->doc_name);
}

void display_patient_details(struct patient *p){
for(int i=0;i<count;i++){
		printf("--------Registerd patient details---------\n");
		printf("Patient ID               : %d\n",(p+i)->id);
		printf("Patient Name             : %s\n",(p+i)->name);
		printf("Patient Gender           : %c\n",(p+i)->gen);
		printf("Patient mobile number    : %ld\n",(p+i)->mob);
		printf("Patient's Doctor name    : %s\n",(p+i)->doc_name);
	}
}

void search_patient_details(struct patient *p,int id){
printf("-----Searched patient detail for patient ID %d is-----\n",id);
	for(int i=0;i<count;i++){
	if((p+i)->id==id){
		printf("Patient Name             : %s\n",(p+i)->name);
		printf("Patient Gender           : %c\n",(p+i)->gen);
		printf("Patient mobile number    : %ld\n",(p+i)->mob);
		printf("Patient's Doctor name    : %s\n",(p+i)->doc_name);
		printf("\n");
	return;
	}
}
printf("Patient details not found\n\n");
}











