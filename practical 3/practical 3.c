#include <stdio.h>
#define MAX 5

int queue[MAX];
int f = -1, r = -1;

void enqueue(int val);
void dequeue();
void display();

int main() {
    int ch, val, a = 1;

    while (a) {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Insert an element to queue\n");
        printf("2. Delete an element from queue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program.\n");
                a = 0;
                break;

            default:
                printf("Enter valid input!\n");
        }
    }

    return 0;
}

// Function to insert an element in queue
void enqueue(int val) {
    if (r == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (f == -1) {
            f = 0;
        }
        r++;
        queue[r] = val;
        printf("Inserted: %d\n", val);
    }
}

// Function to delete an element from queue
void dequeue() {
    if (f == -1 || f > r) {
        printf("Queue is underflow!\n");
    } else {
        printf("Deleted: %d\n", queue[f]);
        f++;
        if (f > r) {
            f = r = -1; // Reset queue when empty
        }
    }
}

// Function to display queue elements
void display() {
    if (f == -1 || f > r) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = f; i <= r; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}