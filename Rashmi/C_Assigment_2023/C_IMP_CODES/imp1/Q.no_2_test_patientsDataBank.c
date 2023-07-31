#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define NAME 20
#define MAX 5
#define MAX_PATIENT 100

typedef struct patients{
	char p_name[NAME];
	char p_gender[10];
	char p_mob_no[11];
	char p_doctor_name[NAME];
	int p_id;
}patient_t;

int function_select(void);             // function for selecting the function
void p_add(patient_t *, int);    // function for add new patients
void p_display(patient_t*, int); // function for display patients details
void p_search(patient_t*, int, int);  //function for search the patients 


int main()
{
	int p_count=0;
	int id, choice;
	patient_t appolo[MAX_PATIENT];  // patients structure array
	//struct patients *pp;     // patients structure pointer

	while(1)   // infine loop for calling again and again 
	{
		choice =function_select();
		switch(choice)
		{
			case 1: 
				p_add(appolo, p_count);
				p_count++;
				break;
		
			case 2: 
				for(int i=0; i<p_count; i++)
					p_display(appolo, i);
				break;
		
			case 3: 
				printf("Enter the patient_id which wants to serch:- \n");
				scanf("%d", &id);
				p_search(appolo, p_count, id);
				break;
			case 4:
				printf("Thankyou !!\n");
				exit(1);
				break;
			default:
				printf("sorry !! Wrong choice !!\n");
		}
	}

return 0;
}

int function_select(void)
{
	int choice;
	printf("***************************************************\n");
	printf("1 for adding the patient:- \n");
	printf("2 for display patient info :- \n");
	printf("3 for searching  the patient:- \n");
	printf("4 for Exit :- \n");
	printf("***************************************************\n");
	printf("Enter your choice :- \n");
	scanf("%d", &choice);
	return choice;
}


void p_add(patient_t *p, int i)
{
		printf("Enter the Details of patients_%d\n", i);
		printf("P_name:- ");
		__fpurge(stdin);
		scanf("%[^\n]s", (p+i)->p_name);
		printf("patients_gender (M/F):- ");
		__fpurge(stdin);
		scanf("%s", (p+i)->p_gender);
		printf("patients_ID(3_Digits):- ");
		scanf("%d", &(p+i)->p_id);
		if(((p+i)->p_id < 100) && ((p+i)->p_id > 1000) )
		{
			printf("Enter again only 3_Digits:- ");
			scanf("%d", &(p+i)->p_id);
		}
		printf("patients_Mobile no-:- ");
		__fpurge(stdin);
		scanf("%s", (p+i)->p_mob_no);
		printf("patients_Doctor_name:- ");
		__fpurge(stdin);
		scanf("%[^\n]s", (p+i)->p_doctor_name);

return ;
}


void p_display(patient_t *p, int i)
{
		printf("Details of patients_%d\n", i);
		printf("P_name:-%s\n", (p+i)->p_name);
		printf("patients_gender :-%s\n",(p+i)->p_gender);
		printf("patients_ID :- %d\n", (p+i)->p_id);
		printf("patients_mob_no- :- %s\n", (p+i)->p_mob_no);
		printf("patients_Doctor_name:- %s\n", (p+i)->p_doctor_name);
return;
}


void p_search(patient_t *p, int n, int id)
{
	for (int i=0; i<n; i++)
	{	
		if(id==(p+i)->p_id)
		{
			printf("Patient found at %d\n",i);
			p_display(p, i);
		}
	}
return;
}
