#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    char fatherName[50];
    int rollNumber;
    int age;
    char studentClass[20];
};

void addNewStudent(struct Student students[], int* count) {
    struct Student newStudent;
    
    printf("\nEnter student details:\n");
    printf("Name: ");
    scanf("%s", newStudent.name);
    printf("Father's Name: ");
    scanf("%s", newStudent.fatherName);
    printf("Roll number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Age: ");
    scanf("%d", &newStudent.age);
    printf("Class: ");
    scanf("%s", newStudent.studentClass);
    
    students[*count] = newStudent;
    (*count)++;
    
    printf("\nStudent added successfully!\n");
}

void searchStudentByRollNumber(const struct Student students[], int count) {
    int rollNumber;
    printf("\nEnter roll number to search: ");
    scanf("%d", &rollNumber);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\nStudent found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Father's Name: %s\n", students[i].fatherName);
            printf("Roll number: %d\n", students[i].rollNumber);
            printf("Age: %d\n", students[i].age);
            printf("Class: %s\n", students[i].studentClass);
            
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\nStudent with roll number %d not found.\n", rollNumber);
    }
}

void showAllStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo students found.\n");
    } else {
        printf("\nList of all students:\n");
        for (int i = 0; i < count; i++) {
            printf("Name: %s\n", students[i].name);
            printf("Father's Name: %s\n", students[i].fatherName);
            printf("Roll number: %d\n", students[i].rollNumber);
            printf("Age: %d\n", students[i].age);
            printf("Class: %s\n", students[i].studentClass);
            printf("\n");
        }
    }
}

int main() {
    struct Student students[100];
    int count = 0;
    char choice;
    
    do {
        printf("===================\n");
        printf(" Welcome to School\n");
        printf("===================\n");
        printf("A: Add new student\n");
        printf("B: Search a student by roll number\n");
        printf("C: Show all students\n");
        printf("D: Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'A':
            case 'a':
                addNewStudent(students, &count);
                break;
                
            case 'B':
            case 'b':
                searchStudentByRollNumber(students, count);
                break;
                
            case 'C':
            case 'c':
                showAllStudents(students, count);
                break;
                
            case 'D':
            case 'd':
                printf("\nGoodbye!\n");
                exit(0);
                
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (1);
    
    return 0;
}

