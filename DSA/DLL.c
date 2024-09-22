#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void createList(Node** head, Node** tail, int* size) {
    printf("Enter the number of contacts: ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        char name[50];
        printf("Enter contact name %d: ", i + 1);
        scanf("%s", name);
        Node* newNode = createNode(name);
        if (*head == NULL) {
            *head = newNode;
            *tail = newNode;
        } else {
            newNode->prev = *tail;
            (*tail)->next = newNode;
            *tail = newNode;
        }
    }
}

void insertContact(Node** head, Node** tail, int position, char* name) {
    Node* newNode = createNode(name);
    if (position == 0) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else {
        Node* temp = *head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        } else {
            *tail = newNode;
        }
    }
}

void deleteContact(Node** head, Node** tail, char* name) {
    Node* temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            } else {
                *tail = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
}

void displayListForward(Node* head) {
    Node* temp = head;
    printf("Contact list (forward): ");
    while (temp != NULL) {
        printf("%s <-> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayListBackward(Node* tail) {
    Node* temp = tail;
    printf("Contact list (backward): ");
    while (temp != NULL) {
        printf("%s <-> ", temp->name);
        temp = temp->prev;
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
    Node* tail = NULL;
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
                createList(&head, &tail, &size);
                displayListForward(head);
                displayListBackward(tail);
                break;
            case 2:
                char name[50];
                printf("Enter the contact's name to insert: ");
                scanf("%s", name);
                int position;
                printf("Enter the position (0-based index) to insert the contact: ");
                scanf("%d", &position);
                insertContact(&head, &tail, position, name);
                displayListForward(head);
                displayListBackward(tail);
                break;
            case 3:
                char deleteMethod;
                printf("Delete by name or position? (n/p): ");
                                scanf(" %c", &deleteMethod);
                if (deleteMethod == 'n') {
                    char deleteName[50];
                    printf("Enter the contact's name to delete: ");
                    scanf("%s", deleteName);
                    deleteContact(&head, &tail, deleteName);
                    displayListForward(head);
                    displayListBackward(tail);
                } else {
                    int deletePosition;
                    printf("Enter the position (0-based index) to delete the contact: ");
                    scanf("%d", &deletePosition);
                    // implement delete by position
                    Node* temp = head;
                    for (int i = 0; i < deletePosition; i++) {
                        temp = temp->next;
                    }
                    if (temp->prev != NULL) {
                        temp->prev->next = temp->next;
                    } else {
                        head = temp->next;
                    }
                    if (temp->next != NULL) {
                        temp->next->prev = temp->prev;
                    } else {
                        tail = temp->prev;
                    }
                    free(temp);
                    displayListForward(head);
                    displayListBackward(tail);
                }
                break;
            case 4:
                displayListForward(head);
                displayListBackward(tail);
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