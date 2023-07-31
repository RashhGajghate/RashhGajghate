#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
int count;
struct patient{

	char p_name[30];
	char d_name[30];
	int age;
	char gender;
	int mob_no;
	int p_id;
};

void add(struct patient []);
void display(struct patient []);
void search(struct patient []);
void modify(struct patient []);

int main(){
	
	struct patient p[10];
	int choice;
	while(1){

		printf("1:Add\n2:Display\n3:Search\n4:Modify\n5:Exit\n");
		scanf("%d",&choice);
	switch(choice){

		case 1:add(p);	
			break;

		case 2:display(p);
			break;

		case 3: search(p);
			break;
			
		case 4:modify(p);
			break;
		case 5:
			exit(0);
			break;
		default:
			break;

	}
	}

	return 0;
}


void add(struct patient pat[])
{
	printf("Enter patient name: ");
	scanf("%s",pat[count].p_name);
	
	printf("Enter Doctor name: ");
	scanf("%s",pat[count].d_name);

	__fpurge(stdin);
	printf("Enter Gender: ");
	scanf("%c",&pat[count].gender);
	
	printf("Enter Mob No: ");
	scanf("%d",&pat[count].mob_no);
	
	printf("Enter Pat ID: ");
	scanf("%d",&pat[count].p_id);
	
	printf("Enter Age: ");
	scanf("%d",&pat[count].age);
	
	count++;
	
	
}
void display(struct patient pat[])
{
	for(int i=0 ; i<count ;i++){
	printf("\n ==== Details of Patient %d ====\n", i+1);
	
	printf("Patient name: %s\n",pat[i].p_name);
	
	printf("Doctor name: %s\n",pat[i].d_name);

	printf("Gender: %c\n", pat[i].gender);
	
	printf("Mob No: %d\n", pat[i].mob_no);
	
	printf("Pat ID: %d\n", pat[i].p_id);
	
	printf("Age: %d\n", pat[i].age);


	}

}
void search(struct patient pat[])
{
	int search,i,flag=0;
	printf("\nEnter Patient ID to search:");
	scanf("%d",&search);
	
	for(i=0 ; i<count ;i++){
	
		if(pat[i].p_id == search){
		flag=1;  //set flag incase patinet found
		break;
		}
	
	}
		printf("Patient index in array = %d\n",i);
		if(flag == 1){
			printf("Patient found succesfully\n");
			printf("=== Patient details are ===\n");
			printf("Patient name: %s\n",pat[i].p_name);
	
			printf("Doctor name: %s\n",pat[i].d_name);

			printf("Gender: %c\n", pat[i].gender);
	
			printf("Mob No: %d\n", pat[i].mob_no);
	
			printf("Pat ID: %d\n", pat[i].p_id);
	
			printf("Age: %d\n", pat[i].age);			
		
		}
		else{
		printf("Patient not found\n");
		}
		
	
}
void modify(struct patient pat[])
{
	int search,i,flag=0;
	printf("\nEnter Patient ID to Modify:");
	scanf("%d",&search);
	
	for(i=0 ; i<count ;i++){
	
		if(pat[i].p_id == search){
		flag=1;  //set flag incase patient found
		break;
		}
	
	}
	
	if(flag == 1){
			printf("Patient found succesfully\n");
			printf("=== Enter Patient details ===\n");
			
			printf("Enter patient name: ");
			scanf("%s",pat[i].p_name);
	
			printf("Enter Doctor name: ");
			scanf("%s",pat[i].d_name);

			__fpurge(stdin);
			printf("Enter Gender: ");
			scanf("%c",&pat[i].gender);
	
			printf("Enter Mob No: ");
			scanf("%d",&pat[i].mob_no);
	
			printf("Enter Age: ");
			scanf("%d",&pat[i].age);		
		
		}
		else{
		printf("Patient not found, cannot modify details\n");
		}
}
