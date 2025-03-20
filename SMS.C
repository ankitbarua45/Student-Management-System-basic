#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct 
{
    char name[50];
    int roll_no;
    float marks;
} 
Student;
Student students[MAX_STUDENTS];
int count = 0;

void addStudent() 
{
    if (count >= MAX_STUDENTS) 
    {
        printf("\nStudent list is full!\n");
        return;
    }
    printf("\nEnter Name: ");
    scanf(" %49[^\n]", students[count].name);
    printf("Enter Roll No: ");
    scanf("%d", &students[count].roll_no);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("\nStudent added successfully!\n");
}

void displayStudents() 
{
    if (count == 0) 
    {
        printf("\nNo student records found!\n");
        return;
    }
    printf("\nStudent Records:\n");
    printf("----------------------------------\n");
    for (int i = 0; i < count; i++) 
    {
        printf("Roll No: %d | Name: %s | Marks: %.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
    printf("----------------------------------\n");
}

void searchStudent() 
{
    int roll;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) 
    {
        if (students[i].roll_no == roll) 
        {
            printf("\nRecord Found: %s | Roll No: %d | Marks: %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
            return;
        }
    }
    printf("\nStudent not found!\n");
}

void deleteStudent() 
{
    int roll;
    printf("\nEnter Roll No to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) 
    {
        if (students[i].roll_no == roll) 
        {
            for (int j = i; j < count - 1; j++) 
            {
                students[j] = students[j + 1];
            }
            count--;
            printf("\nStudent record deleted successfully!\n");
            return;
        }
    }
    printf("\nStudent not found!\n");
}
int main() 
{
    int choice;
    do 
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Delete Student\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
