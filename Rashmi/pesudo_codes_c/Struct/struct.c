#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//global variables declaration
int s_count=0,t_count=0;

union id_proof
{
    char aadhar[20];
    char pass[20];
    char drive[20];
};
struct teacher{
    char *name;
    char *surname;
    char *subject;
    int join;
    int reg;
    union id_proof id;
};
struct student{
    char *name;
    char *surname;
    char *f_name;
    char class;
    int roll;
    union id_proof id;
};

//global struct array declaration
struct student std[10];
struct teacher tec[10];

//function declaration
void add_student(struct student []);
void add_teacher(struct teacher []);
void display_student(struct student []);
void display_teacher(struct teacher []);
void search(struct teacher [],struct student []);
void modify(struct teacher [],struct student []);

//Menu Function
void menu(){
    int choice;
    lable:
    printf("\n\n Wellcome to college\n");
    printf("\n1 : Add Student\n2 : Add Teacher\n3 : Display Students\n4 : Display Teachers\n5 : Search\n6 : Modify\n7 : Exit\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1 : add_student(std);
        break;
    case 2 : add_teacher(tec);
        break;
    case 3 : display_student(std);
        break;
    case 4 : display_teacher(tec);
        break;
    case 5 : search(tec,std);
        break;
    case 6 : modify(tec,std); 
        break;
    case 7 :  
        break;
    default: printf("Invalid input ");
             goto lable;
        break;
    }

}

//Main Function
int main(){
    
    menu();
    
    //free memory for Student
    for(int i=0;i<s_count;i++){
        free(std[i].name);
        free(std[i].surname);
        free(std[i].f_name);

    }
    printf("\n\nStudent heap memory free succesfully ");

     //free memory for Teacher
    for(int i=0;i<t_count;i++){
        free(tec[i].subject);
        free(tec[i].surname);
        free(tec[i].name);

    }
    printf("\n\nTeacher heap memory free succesfully ");
    
}

//Add Student Function
void add_student(struct student stu[]){
    int i=s_count,choice,a;
    while(a==true){
       stu[i].name=(char *)malloc(sizeof(char)*10);
       stu[i].surname=(char *)malloc(sizeof(char)*10);
       stu[i].f_name=(char *)malloc(sizeof(char)*10);
    
       printf("\nStudent : %d",i+1);
       printf("\n\nEnter Name : ");
       scanf("\n%s",stu[i].name);
       printf("\n\nEnter Surname : ");
       scanf("\n%s",stu[i].surname);
       printf("\n\nEnter Father Name : ");
       scanf("\n%s",stu[i].f_name);
       printf("\n\nEnter Class Div : ");
       scanf("\n%c",&stu[i].class);
       printf("\n\nEnter Roll No : ");
       scanf("\n%d",&stu[i].roll);
        lable:
       printf("\n1 : Aadhar card\n2 : Passport\n3 : Driving Licence \n");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1: printf("\n\nEnter Aadhar card : ");
            scanf("\n%s",stu[i].id.aadhar);
        break;
        case 2: printf("\n\nEnter Passport : ");
            scanf("\n%s",stu[i].id.pass);
        break;
        case 3: printf("\n\nEnter Driving Licence : ");
            scanf("\n%s",stu[i].id.drive);
        break;
        default: printf("Invalid input");
               goto lable;
       }
       s_count++;
       a=false;
       menu();
       



    }
}

//Display Student Function
void display_student(struct student stu[]){
    for(int i=0;i<s_count;i++){
        printf("\n\n student %d\nName : %s\nSurname : %s\nFathers Name : %s\nClass Div : %c\nRoll No : %d\nId Proof : %s",
        i+1,stu[i].name,stu[i].surname,stu[i].f_name,stu[i].class,stu[i].roll,stu[i].id.aadhar);
    }
    menu();
}

//Add Teacher Function 
void add_teacher(struct teacher tec[])
{
    int i=t_count,choice,a;
    while(a==true){
       tec[i].name=(char *)malloc(sizeof(char)*10);
       tec[i].surname=(char *)malloc(sizeof(char)*10);
       tec[i].subject=(char *)malloc(sizeof(char)*10);
    
       printf("\nTeacher : %d",i+1);
       printf("\n\nEnter Name : ");
       scanf("\n%s",tec[i].name);
       printf("\n\nEnter Surname : ");
       scanf("\n%s",tec[i].surname);
       printf("\n\nEnter Subject : ");
       scanf("\n%s",tec[i].subject);
       printf("\n\nEnter Joining year : ");
       scanf("\n%d",&tec[i].join);
       printf("\n\nEnter Reg No : ");
       scanf("\n%d",&tec[i].reg);
       lable:
       printf("\n1 : Aadhar card\n2 : Passport\n3 : Driving Licence \n");
       scanf("\n%d",&choice);
       switch (choice)
       {
       case 1: printf("\n\nEnter Aadhar card : ");
            scanf("\n%s",tec[i].id.aadhar);
             break;
        case 2: printf("\n\nEnter Passport : ");
            scanf("\n%s",tec[i].id.pass);
             break;
        case 3: printf("\n\nEnter Driving Licence : ");
            scanf("\n%s",tec[i].id.drive);
              break;
        default: printf("Invalid input");
               goto lable;
       }
       t_count++;
       a=false;
       menu();
       



    }
}

//Display Teacher Function
void display_teacher(struct teacher tec[]){
    for(int i=0;i<t_count;i++){
        printf("\n\n Teacher %d\nName : %s\nSurname : %s\nSubject : %s\nJoining Year : %d\nReg No : %d\nId Proof : %s",
        i+1,tec[i].name,tec[i].surname,tec[i].subject,tec[i].join,tec[i].reg,tec[i].id.aadhar);
    }
    menu();
}

//Search Function Teacher/Student
void search(struct teacher tec[],struct student stu[]){
    int choice,check;
    printf("\n1 : Teacher \n2 : Student");
    scanf("%d",&choice);
    if(choice == 1){
        printf("\nEnter the Reg No of Teacher : ");
        scanf("%d",&check);
        for(int i=0;i<t_count;i++){
            if(tec[i].reg==check){
                 printf("\n\n Teacher %d\nName : %s\nSurname : %s\nSubject : %s\nJoining Year : %d\nReg No : %d\nId Proof : %s",
        i+1,tec[i].name,tec[i].surname,tec[i].subject,tec[i].join,tec[i].reg,tec[i].id.aadhar);
            }
        }
    }
    if(choice == 2){
        printf("\nEnter the Roll No of Student : ");
        scanf("%d",&check);
        for(int i=0;i<s_count;i++){
            if(std[i].roll==check){
                 printf("\n\n student %d\nName : %s\nSurname : %s\nFathers Name : %s\nClass Div : %c\nRoll No : %d\nId Proof : %s",
        i+1,stu[i].name,stu[i].surname,stu[i].f_name,stu[i].class,stu[i].roll,stu[i].id.aadhar);
            }
        }
    }
    else{
        printf("\nInvalid Id ");
    }
    menu();
}

//Modify Function Teacher/Student
void modify(struct teacher tec[],struct student stu[]){
     int choice,check;
    printf("\n1 : Teacher \n2 : Student");
    scanf("%d",&choice);
    if(choice == 1){
        printf("\nEnter the Reg No of Teacher : ");
        scanf("%d",&check);
        for(int i=0;i<t_count;i++){
            if(tec[i].reg==check){
                printf("\n\nEnter Surname : ");
                 scanf("\n%s",tec[i].surname);
                printf("\n\nEnter Subject : ");
                scanf("\n%s",tec[i].subject);
                printf("\n\nEnter Joining year : ");
                scanf("\n%d",&tec[i].join);
            }
        }
        printf("\nUpdated Sucessfully \n");
    }
    if(choice == 2){
        printf("\nEnter the Roll No of Student : ");
        scanf("%d",&check);
        for(int i=0;i<s_count;i++){
            if(std[i].roll==check){
                printf("\n\nEnter Surname : ");
                scanf("\n%s",stu[i].surname);
                printf("\n\nEnter Father Name : ");
                scanf("\n%s",stu[i].f_name);
                printf("\n\nEnter Class Div : ");
                scanf("\n%c",&stu[i].class);
            }
        }
        printf("\nUpdated Sucessfully \n");
    }
    else{
        printf("\nInvalid Id ");
    }
    menu();
}