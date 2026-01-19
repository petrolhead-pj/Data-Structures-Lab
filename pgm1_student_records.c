//Write a C program to store and manage a list of records student records 
//(student name, usn ,department and total marks) using structures. Using 
//dynamic memory allocation and pointers write functions to create student 
//records, add the records, display and search records based on usn.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

struct Student {
    int usn;
    char name[SIZE];
    char dept[SIZE];
    int totalMarks;
};

/* Add student details */
void addStudent(struct Student *stud, int index) {       //stud is a pointer which points to the first student block/node/structure
    printf("Enter USN: ");
    scanf("%d", &stud[index].usn);

    printf("Enter Name: ");
    scanf(" %[^\n]", stud[index].name);

    printf("Enter Department: ");
    scanf(" %[^\n]", stud[index].dept);

    printf("Enter Total Marks: ");
    scanf("%d", &stud[index].totalMarks);

    printf("Record added\n");
}

/* Display records */
void displayStudents(struct Student *stud, int count) {
    if (count == 0) {
        printf("No records\n");
        return;
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("USN: %d\nName: %s\nDept: %s\nMarks: %d\n\n",
               stud[i].usn, stud[i].name, stud[i].dept, stud[i].totalMarks);
    }
}

/* Search by USN */
void searchByUSN(struct Student *stud, int count) {
    int search, found = 0;

    printf("Enter USN to search: ");
    scanf("%d", &search);

    for (int i = 0; i < count; i++) {
        if (stud[i].usn == search) {
            printf("\nRecord Found:\n");
            printf("USN: %d\nName: %s\nDept: %s\nMarks: %d\n",
                   stud[i].usn, stud[i].name, stud[i].dept, stud[i].totalMarks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student record not found\n");
}

int main() {
    struct Student *stud = NULL;               
    int index = 0, choice;

    while (1) {
        printf("\nMenu: 1.Add Student 2.Display 3.Search 4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                stud = realloc(stud, (index + 1) * sizeof(struct Student));         //!stud to pointer hai that stores memory and *stud stores data at that memory..so we want to change the memory size not data so used stud instead of *stud
                if (stud == NULL) {
                    printf("Memory allocation failed\n");
                    exit(1);
                }
                addStudent(stud, index);
                index++;
                break;

            case 2:
                displayStudents(stud, index);
                break;

            case 3:
                searchByUSN(stud, index);
                break;

            case 4:
                free(stud);
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
