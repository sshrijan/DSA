
#include <stdio.h>
#define MAX 5

struct stack {
    int item[MAX];
    int top;
};

typedef struct stack st;
st s1;

void push() {
    int x;
    if (s1.top == MAX - 1) {
        printf("Stack is full. Items cannot be inserted.\n");
    } else {
        printf("Enter the item to be PUSHED: ");
        scanf("%d", &x);
        s1.item[++s1.top] = x;
    }
}

void pop() {
    if (s1.top == -1) {
        printf("Stack is empty. Nothing to delete.\n");
    } else {
        printf("The POPPED item is: %d\n", s1.item[s1.top--]);
    }
}

void display() {
    if (s1.top == -1) {
        printf("Stack is empty. Nothing to display.\n");
    } else {
        printf("Items in the stack are:\n");
        for (int i = s1.top; i >= 0; i--) {
            printf("%d\n", s1.item[i]);
        }
    }
}

int main() {
    int choice;
    s1.top = -1;

    while (1) {
        printf("\n***** Enter the Choice ******\n");
        printf("1. Push item in the stack\n");
        printf("2. Pop item from the stack\n");
        printf("3. Display items in the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); return 0;
            default: printf("Enter a valid choice!\n");
        }
    }

    return 0;
}
