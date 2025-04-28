#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Insert at end
void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
}

// Delete a node by value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    // Search for node
    do {
        if (current->data == value) {
            if (current->next == current && current->prev == current) {
                // Only one node
                free(current);
                head = NULL;
            } else {
                // More than one node
                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == head) {
                    head = current->next;
                }

                free(current);
            }

            printf("Node with value %d deleted.\n", value);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Value %d not found in the list.\n", value);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function with menu
int main() {
    int choice, value;

    do {
        printf("\nDoubly Circular Linked List Menu\n");
        printf("1. Insert at End\n");
        printf("2. Delete Node by Value\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
