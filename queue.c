#include <stdio.h>
#define MAX 5

struct queue {
    int item[MAX];
    int rear, front;
};

typedef struct queue st;
st q1;

void push() {
    int x;
    if (q1.rear == MAX - 1) {
        printf("Queue is full. Items cannot be inserted.\n");
    } else {
        printf("Enter the item to be PUSHED: ");
        scanf("%d", &x);
        if (q1.front == -1)  // If inserting the first element, reset front
            q1.front = 0;
        q1.item[++q1.rear] = x;
    }
}

void pop() {
    if (q1.front == -1 || q1.front > q1.rear) {
        printf("Queue is empty. Nothing to delete.\n");
    } else {
        printf("The POPPED item is: %d\n", q1.item[q1.front]);
        q1.front++;
        if (q1.front > q1.rear) {  // Reset queue when all elements are deleted
            q1.front = -1;
            q1.rear = -1;
        }
    }
}

void display() {
    if (q1.front == -1) {
        printf("Queue is empty. Nothing to display.\n");
    } else {
        printf("Items in the Queue are:\n");
        for (int i = q1.front; i <= q1.rear; i++) {
            printf("%d\n", q1.item[i]);
        }
    }
}

int main() {
    int choice;
    q1.front = -1;
    q1.rear = -1;

    while (1) {
        printf("\n***** Enter the Choice ******\n");
        printf("1. Push item in the queue\n");
        printf("2. Pop item from the queue\n");
        printf("3. Display items in the queue\n");
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
