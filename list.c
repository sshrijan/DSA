#include <stdio.h>
int a[50], size, i, num, pos;

    void insert() {
        printf("Enter the element that you want to insert: ");
        scanf("%d", &num);

        printf("Enter the position where you want to insert it (1-based index): ");
        scanf("%d", &pos);

        if (pos <= 0 || pos > size + 1) {
            printf("Invalid Position!\n");
            return;
        }

        // Shifting elements to the right
        for (i = size; i >= pos; i--) {
            a[i] = a[i - 1];
        }

        // Insert element at the given position
        a[pos - 1] = num;
        size++;

        printf("Element inserted successfully!\n");
    }

    void delete() {
        printf("Enter the position of the element you want to delete (1-based index): ");
        scanf("%d", &pos);

        if (pos <= 0 || pos > size) {
            printf("Invalid Position!\n");
            return;
        }

        // Store deleted element
        int trashBin = a[pos - 1];

        // Shift elements to the left
        for (i = pos - 1; i < size - 1; i++) {
            a[i] = a[i + 1];
        }

        size--;

        printf("Element %d deleted successfully!\n", trashBin);
    }

void display() {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Current elements in the list: ");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size > 50 || size < 0) {
        printf("Invalid size! Must be between 1 and 50.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    while (1) {
        int expression;

        printf("\n***** MENU *****\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &expression);

        switch (expression) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
