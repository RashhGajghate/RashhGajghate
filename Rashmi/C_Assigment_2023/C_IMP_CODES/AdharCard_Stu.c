#include <stdio.h>
#include <string.h>
#include<stdio_ext.h>

#define MAX_STUDENTS 100

typedef enum {
    A = 'A',
    B = 'B',
    C = 'C',
    D = 'D'
} MenuOption;

typedef enum {
    AadharCard,
    VoterCard,
    DrivingLicense
} GovtIDType;

typedef union {
    char aadharCard[16];
    char voterCard[16];
    char drivingLicense[16];
} GovtID;

typedef struct {
    char name[50];
    char fatherName[50];
    int rollNumber;
    GovtIDType idType;
    GovtID govtID;
} Student;

void displayMenu() {
    printf("===================\n");
    printf(" Welcome to College\n");
    printf("===================\n");
    printf("A: Add new student\n");
    printf("B: Search a student by roll number\n");
    printf("C: Show all students\n");
    printf("D: Exit\n");
}

void addStudent(Student* students, int* count) {
    if (*count == MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }
    
    Student newStudent;
    printf("Enter name: ");
    __fpurge(stdin);
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';  // Remove newline character
    
    printf("Enter father's name: ");
    __fpurge(stdin);
    fgets(newStudent.fatherName, sizeof(newStudent.fatherName), stdin);
    newStudent.fatherName[strcspn(newStudent.fatherName, "\n")] = '\0';  // Remove newline character
    
    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNumber);
    
    printf("Enter Govt ID type (0 - Aadhar Card, 1 - Voter Card, 2 - Driving License): ");
    int idType;
    scanf("%d", &idType);
    
    newStudent.idType = (GovtIDType)idType;
    
    // Clear input buffer
    while (getchar() != '\n');
    
    switch (newStudent.idType) {
        case AadharCard:
            printf("Enter Aadhar Card number: ");
            fgets(newStudent.govtID.aadharCard, sizeof(newStudent.govtID.aadharCard), stdin);
            newStudent.govtID.aadharCard[strcspn(newStudent.govtID.aadharCard, "\n")] = '\0';  // Remove newline character
            break;
        case VoterCard:
            printf("Enter Voter Card number: ");
            fgets(newStudent.govtID.voterCard, sizeof(newStudent.govtID.voterCard), stdin);
            newStudent.govtID.voterCard[strcspn(newStudent.govtID.voterCard, "\n")] = '\0';  // Remove newline character
            break;
        case DrivingLicense:
            printf("Enter Driving License number: ");
            fgets(newStudent.govtID.drivingLicense, sizeof(newStudent.govtID.drivingLicense), stdin);
            newStudent.govtID.drivingLicense[strcspn(newStudent.govtID.drivingLicense, "\n")] = '\0';  // Remove newline character
            break;
    }
    
    students[*count] = newStudent;
    (*count)++;
    
    printf("Student added successfully.\n");
}

void searchStudent(const Student* students, int count) {
    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);
    
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student found:\n");
            printf("Name: %s\n", students[i].name);
            printf("Father's Name: %s\n", students[i].fatherName);
            printf("Roll Number: %d\n", students[i].rollNumber);
            
            switch (students[i].idType) {
                case AadharCard:
                    printf("Govt ID: Aadhar Card (%s)\n", students[i].govtID.aadharCard);
                    break;
                case VoterCard:
                    printf("Govt ID: Voter Card (%s)\n", students[i].govtID.voterCard);
                    break;
                case DrivingLicense:
                    printf("Govt ID: Driving License (%s)\n", students[i].govtID.drivingLicense);
                    break;
            }
            
            return;
        }
    }
    
    printf("Student with roll number %d not found.\n", rollNumber);
}

void showAllStudents(const Student* students, int count) {
    if (count == 0) {
        printf("No students found.\n");
        return;
    }
    
    printf("List of all students:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Father's Name: %s\n", students[i].fatherName);
        printf("Roll Number: %d\n", students[i].rollNumber);
        
        switch (students[i].idType) {
            case AadharCard:
                printf("Govt ID: Aadhar Card (%s)\n", students[i].govtID.aadharCard);
                break;
            case VoterCard:
                printf("Govt ID: Voter Card (%s)\n", students[i].govtID.voterCard);
                break;
            case DrivingLicense:
                printf("Govt ID: Driving License (%s)\n", students[i].govtID.drivingLicense);
                break;
        }
        
        printf("-------------\n");
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    
    MenuOption option;
    do {
        displayMenu();
        printf("Enter option: ");
        scanf(" %c", (char*)&option);
        
        switch (option) {
            case A:
                addStudent(students, &studentCount);
                break;
            case B:
                searchStudent(students, studentCount);
                break;
            case C:
                showAllStudents(students, studentCount);
                break;
            case D:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        
        // Clear input buffer
        while (getchar() != '\n');
        
        printf("==========================================\n\n");
    } while (option != D);
    
    return 0;
}

