/*
 * Filename: circular_linked_list_operations.c
 * Description: This program performs various operations on a circular singly linked list.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o circular_linked_list_operations circular_linked_list_operations.c
 * Execution: ./circular_linked_list_operations
 *
 * Operations:
 * A. Creation
 * B. Traversal
 * C. Insertion at the beginning
 * D. Insertion at the end
 * E. Insertion at any location
 * F. Deletion of the first node
 * G. Deletion of the last node
 * H. Deletion from any location
 *
 * Time Complexity:
 * - Insertion: O(1) for beginning, O(n) for end and any location
 * - Deletion: O(1) for first node, O(n) for last node and any location
 * - Traversal: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for a circular singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* create(int data);
Node* createInitialNode();
void traverse(Node* head);
Node* insertatbeg(Node* head, int data);
Node* insertatend(Node* head, int data);
Node* insertatpos(Node* head, int data, int position);
Node* dltfirst(Node* head);
Node* dltlast(Node* head);
Node* dltpos(Node* head, int position);
void freeList(Node* head);

int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n*** Circular Linked List Menu ***\n");
        printf("1. Creation\n");
        printf("2. Traversal\n");
        printf("3. Insertion at Beginning\n");
        printf("4. Insertion at End\n");
        printf("5. Insertion at Position\n");
        printf("6. Delete First Node\n");
        printf("7. Delete Last Node\n");
        printf("8. Deletion at Position\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createInitialNode();
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &data);
                head = insertatbeg(head, data);
                break;
            case 4:
                printf("Enter value to insert at the end: ");
                scanf("%d", &data);
                head = insertatend(head, data);
                break;
            case 5:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertatpos(head, data, position);
                break;
            case 6:
                head = dltfirst(head);
                break;
            case 7:
                head = dltlast(head);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = dltpos(head, position);
                break;
            case 9:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

Node* create(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; // Points to itself, making it circular
    return newNode;
}

Node* createInitialNode() {
    int data;
    printf("Enter data for the node: ");
    scanf("%d", &data);
    return create(data);
}

void traverse(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

Node* insertatbeg(Node* head, int data) {
    Node* newNode = create(data);
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertatend(Node* head, int data) {
    Node* newNode = create(data);
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* insertatpos(Node* head, int data, int position) {
    if (position == 1) {
        return insertatbeg(head, data);
    }

    Node* newNode = create(data);
    Node* temp = head;

    int i;
    for (i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && position > 1) {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* dltfirst(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    Node* temp = head;
    if (temp->next == head) {
        free(temp);
        return NULL;
    }

    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    free(temp);
    return head;
}

Node* dltlast(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    Node* temp = head;
    if (temp->next == head) {
        free(temp);
        return NULL;
    }

    Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
    return head;
}

Node* dltpos(Node* head, int position) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    if (position == 1) {
        return dltfirst(head);
    }

    Node* temp = head;
    Node* prev = NULL;

    int i;
    for (int i = 1; i < position && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head && position > 1) {
        printf("Position out of bounds.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

void freeList(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* temp = head;
    Node* nextNode;

    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
}
