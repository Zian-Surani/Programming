#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

void createList(char students[][MAX_NAME_LENGTH], int* size) {
    printf("Enter the number of students: ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("Enter student name %d: ", i + 1);
        scanf("%s", students[i]);
    }
}

void insertStudent(char students[][MAX_NAME_LENGTH], int* size, int position, char* name) {
    for (int i = *size; i > position; i--) {
        strcpy(students[i], students[i - 1]);
    }
    strcpy(students[position], name);
    (*size)++;
}

void deleteStudent(char students[][MAX_NAME_LENGTH], int* size, int position) {
    for (int i = position; i < *size - 1; i++) {
        strcpy(students[i], students[i + 1]);
    }
    (*size)--;
}

void displayList(char students[][MAX_NAME_LENGTH], int size) {
    printf("Student list: [");
    for (int i = 0; i < size; i++) {
        printf("%s", students[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void searchStudent(char students[][MAX_NAME_LENGTH], int size, char* name) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i], name) == 0) {
            printf("%s found at position %d\n", name, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("%s not found\n", name);
    }
}

int main() {
    char students[MAX_STUDENTS][MAX_NAME_LENGTH];
    int size = 0;

    while (1) {
        printf("1. Create the list of students\n");
        printf("2. Insert a new student\n");
        printf("3. Delete a student\n");
        printf("4. Display student list\n");
        printf("5. Search for a student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(students, &size);
                displayList(students, size);
                break;
            case 2:
                char name[MAX_NAME_LENGTH];
                printf("Enter the student's name to insert: ");
                scanf("%s", name);
                int position;
                printf("Enter the position (0-based index) to insert the student: ");
                scanf("%d", &position);
                insertStudent(students, &size, position, name);
                displayList(students, size);
                break;
            case 3:
                char deleteMethod;
                printf("Delete by name or position? (n/p): ");
                scanf(" %c", &deleteMethod);
                if (deleteMethod == 'n') {
                    char deleteName[MAX_NAME_LENGTH];
                    printf("Enter the student's name to delete: ");
                    scanf("%s", deleteName);
                    for (int i = 0; i < size; i++) {
                        if (strcmp(students[i], deleteName) == 0) {
                            deleteStudent(students, &size, i);
                            displayList(students, size);
                            break;
                        }
                    }
                } else {
                    int deletePosition;
                    printf("Enter the position (0-based index) to delete the student: ");
                    scanf("%d", &deletePosition);
                    deleteStudent(students, &size, deletePosition);
                    displayList(students, size);
                }
                break;
            case 4:
                displayList(students, size);
                break;
            case 5:
                char searchName[MAX_NAME_LENGTH];
                printf("Enter the student's name to search: ");
                scanf("%s", searchName);
                searchStudent(students, size, searchName);
                break;
            case 6:
                printf("Exiting the program...\n");
                return 0;
        }
    }

    return 0;
}