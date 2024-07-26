/*
 * Filename: queue_operations.c
 * Description: This program performs Insert, Delete, and Traverse operations on a queue implemented using an array.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o queue_operations queue_operations.c
 * Execution: ./queue_operations
 *
 * Queue Operations Algorithm:
 * 1. Initialize the queue, front, and rear variables.
 * 2. Display the menu for queue operations.
 * 3. For INSERT operation:
 *    a. Check for queue overflow using simple condition.
 *    b. If not overflow, read the value to be inserted and add it to the rear of the queue.
 * 4. For DELETE operation:
 *    a. Check for queue underflow.
 *    b. If not underflow, remove the element from the front of the queue and print it.
 * 5. For TRAVERSE operation:
 *    a. Check if the queue is empty.
 *    b. If not empty, print all elements from the front to the rear of the queue using a for loop.
 * 6. Continue until the user chooses to exit.
 *
 * Time Complexity:
 * - INSERT: O(1)
 * - DELETE: O(1)
 * - TRAVERSE: O(n) where n is the number of elements in the queue
 *
 * Space Complexity: O(SIZE) where SIZE is the maximum number of elements in the queue
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Global declarations
int queue[SIZE];
int front = -1;
int rear = -1;

// Function prototypes
void enque();
void deque();
void traverse();

int main() {
    int choice;

    while (1) {
        printf("\n*** Queue Menu ***\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. TRAVERSE\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enque();
                break;
            case 2:
                deque();
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

void enque() {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert any more elements.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        printf("Enter the value to be inserted: ");
        scanf("%d", &queue[rear]);
        printf("Inserted %d into the queue\n", queue[rear]);
    }
}

void deque() {
    if (front == -1) {
        printf("Queue Underflow! No elements to delete.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1; // Queue is empty
        } else {
            front++;
        }
    }
}

void traverse() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
