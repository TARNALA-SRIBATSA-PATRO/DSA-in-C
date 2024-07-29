/*
 * Filename: double_linked_list_operations.c
 * Description: This program performs various operations on a doubly linked list.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o double_linked_list_operations double_linked_list_operations.c
 * Execution: ./double_linked_list_operations
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

// Structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
        printf("\n*** Doubly Linked List Menu ***\n");
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
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* createInitialNode() {
    int data;
    printf("Enter data for the node: ");
    scanf("%d", &data);
    return create(data);
}

void traverse(Node* head) {
    Node* temp = head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* insertatbeg(Node* head, int data) {
    Node* newNode = create(data);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    return head;
}

Node* insertatend(Node* head, int data) {
    Node* newNode = create(data);
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* insertatpos(Node* head, int data, int position) {
    if (position == 1) {
        return insertatbeg(head, data);
    }

    Node* newNode = create(data);

    Node* temp = head;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
    return head;
}

Node* dltfirst(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    return head;
}

Node* dltlast(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    Node* temp = head;
    if (temp->next == NULL) {
        free(temp);
        return NULL;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    return head;
}

Node* dltpos(Node* head, int position) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    Node* temp = head;
    if (position == 1) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
  
    int i;
    for (i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    return head;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
