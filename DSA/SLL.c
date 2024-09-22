#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

Node* createNode(char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void createList(Node** head, int* size) {
    printf("Enter the number of contacts: ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        char name[50];
        printf("Enter contact name %d: ", i + 1);
        scanf("%s", name);
        Node* newNode = createNode(name);
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insertContact(Node** head, int position, char* name) {
    Node* newNode = createNode(name);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteContact(Node** head, char* name) {
    Node* temp = *head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    printf("Contact list: ");
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

void searchContact(Node* head, char* name) {
    Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("%s found at position %d\n", name, position);
            return;
        }
        position++;
        temp = temp->next;
    }
    printf("%s not found\n", name);
}

int main() {
    Node* head = NULL;
    int size = 0;

    while (1) {
        printf("1. Create the list of contacts\n");
        printf("2. Insert a new contact\n");
        printf("3. Delete a contact\n");
        printf("4. Display contact list\n");
        printf("5. Search for a contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head, &size);
                displayList(head);
                break;
            case 2:
                char name[50];
                printf("Enter the contact's name to insert: ");
                scanf("%s", name);
                int position;
                printf("Enter the position (0-based index) to insert the contact: ");
                scanf("%d", &position);
                insertContact(&head, position, name);
                displayList(head);
                break;
            case 3:
                char deleteMethod;
                printf("Delete by name or position? (n/p): ");
                scanf(" %c", &deleteMethod);
                if (deleteMethod == 'n') {
                    char deleteName[50];
                    printf("Enter the contact's name to delete: ");
                    scanf("%s", deleteName);
                    deleteContact(&head, deleteName);
                    displayList(head);
                } else {
                    int deletePosition;
                    printf("Enter the position (0-based index) to delete the contact: ");
                    scanf("%d", &deletePosition);
                    // implement delete by position
                }
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                char searchName[50];
                printf("Enter the contact's name to search: ");
                scanf("%s", searchName);
                searchContact(head, searchName);
                break;
            case 6:
                printf("Exiting the program...\n");
                return 0;
        }
    }

    return 0;
}