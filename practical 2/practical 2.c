#include <stdio.h>
#include <string.h>
#define MAX 50

int stack[MAX];
int top = -1;

// Function to push an element into the stack
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        stack[++top] = x;
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
    } else {
        printf("Popped: %d\n", stack[top--]);
    }
}

// Function to display stack elements
void display() {
    if (top == -1) {
        printf("Stack empty!\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Function to check if a string is palindrome using stack
void palindrome(char str[]) {
    int n = strlen(str);
    int flag = 1;
    top = -1;

    // Push all characters into the stack
    for (int i = 0; i < n; i++) {
        push(str[i]);
    }

    // Compare characters while popping
    for (int i = 0; i < n; i++) {
        if (str[i] != stack[top--]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");
}

int main() {
    int ch, val;
    char str[50];

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Enter string: ");
                scanf("%s", str);
                palindrome(str);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
