#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to delete a node
void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    if (temp == NULL) return; // Empty list
    
    // If the node to be deleted is the head
    if (temp->data == data) {
        *head = temp->next;
        if (*head != NULL) (*head)->prev = NULL;
        free(temp);
        return;
    }
    
    // Traverse the list to find the node
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    
    if (temp == NULL) return; // Node not found

    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    
    free(temp);
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete a Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Current List: ");
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
