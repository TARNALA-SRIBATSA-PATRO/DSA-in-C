/*
 * Filename: stack_operations.c
 * Description: This program performs PUSH, POP, and TRAVERSE operations on a stack implemented using an array.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o stack_operations stack_operations.c
 * Execution: ./stack_operations
 *
 * Stack Operations Algorithm:
 * 1. Initialize the stack and top variable.
 * 2. Display the menu for stack operations.
 * 3. For PUSH operation:
 *    a. Check for stack overflow.
 *    b. If not overflow, read the value to be pushed and add it to the stack.
 * 4. For POP operation:
 *    a. Check for stack underflow.
 *    b. If not underflow, remove the top element and print it.
 * 5. For TRAVERSE operation:
 *    a. Check if the stack is empty.
 *    b. If not empty, print all elements in the stack.
 * 6. Continue until the user chooses to exit.
 *
 * Time Complexity:
 * - PUSH: O(1)
 * - POP: O(1)
 * - TRAVERSE: O(n) where n is the number of elements in the stack
 *
 * Space Complexity: O(SIZE) where SIZE is the maximum number of elements in the stack
 */
 
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Global declarations
int stack[SIZE];
int top = -1;

// Function prototypes
void push();
void pop();
void traverse();

int main() {
    int choice;

    while(1) {
        printf("\n*** Stack Menu ***\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. TRAVERSE\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void push() {
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push any more elements.\n");
    } else {
        printf("Enter the value to be pushed: ");
        scanf("%d", &stack[++top]);
        printf("Pushed %d into the stack\n", stack[top]);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
}

void traverse() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are: ");
        int i;
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
