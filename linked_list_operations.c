/*
 * Filename: linked_list_operations.c
 * Description: This program performs various operations on a singly linked list.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o linked_list_operations linked_list_operations.c
 * Execution: ./linked_list_operations
 *
 * Operations:
 * a. Creation
 * b. Traversal
 * c. Insertion at the beginning
 * d. Insertion at the end
 * e. Insertion at any location
 * f. Deletion of the first node
 * g. Deletion of the last node
 * h. Deletion from any location
 * i. Sorting
 * j. Searching
 * k. Reversing
 *
 * Time Complexity:
 * - Insertion: O(1) for beginning, O(n) for end and any location
 * - Deletion: O(1) for first node, O(n) for last node and any location
 * - Traversal: O(n)
 * - Sorting: O(n^2) for bubble sort, O(n log n) for merge sort
 * - Searching: O(n)
 * - Reversing: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createList();
void traverseList(Node* head);
Node* insertAtBeginning(Node* head, int data);
Node* insertAtEnd(Node* head, int data);
Node* insertAtPosition(Node* head, int data, int position);
Node* deleteFirstNode(Node* head);
Node* deleteLastNode(Node* head);
Node* deleteAtPosition(Node* head, int position);
void sortList(Node* head);
Node* searchList(Node* head, int data);
Node* reverseList(Node* head);
void freeList(Node* head);

int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\n*** Linked List Menu ***\n");
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete First Node\n");
        printf("7. Delete Last Node\n");
        printf("8. Delete at Position\n");
        printf("9. Sort List\n");
        printf("10. Search List\n");
        printf("11. Reverse List\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                traverseList(head);
                break;
            case 3:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 4:
                printf("Enter value to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 5:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 6:
                head = deleteFirstNode(head);
                break;
            case 7:
                head = deleteLastNode(head);
                break;
            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 9:
                sortList(head);
                break;
            case 10:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (searchList(head, data))
                    printf("Value %d found in the list.\n", data);
                else
                    printf("Value %d not found in the list.\n", data);
                break;
            case 11:
                head = reverseList(head);
                break;
            case 12:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

Node* createList() {
    Node* head = NULL;
    Node* temp = NULL;
    Node* current = NULL;
    int data, n, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return NULL;
    }

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        temp = (Node*)malloc(sizeof(Node));
        temp->data = data;
        temp->next = NULL;
        
        if (head == NULL) {
            head = temp;
            current = head;
        } else {
            current->next = temp;
            current = temp;
        }
    }

    return head;
}

void traverseList(Node* head) {
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

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

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
    temp->next = newNode;
    return head;
}

Node* deleteFirstNode(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteLastNode(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteAtPosition(Node* head, int position) {
    if (position == 1) {
        return deleteFirstNode(head);
    }

    Node* temp = head;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

void sortList(Node* head) {
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

Node* searchList(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
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
