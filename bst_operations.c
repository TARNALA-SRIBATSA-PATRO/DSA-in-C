/*
 * Filename: bst_operations.c
 * Description: This program performs various operations on a Binary Search Tree (BST).
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o bst_operations bst_operations.c
 * Execution: ./bst_operations
 *
 * Operations:
 * a. Insert
 * b. Delete
 * c. Search
 * d. FindMax
 * e. FindMin
 * f. Pre-order Traversal
 * g. In-order Traversal
 * h. Post-order Traversal
 *
 * Time Complexity:
 * - Insert: O(log n) on average, O(n) in the worst case
 * - Delete: O(log n) on average, O(n) in the worst case
 * - Search: O(log n) on average, O(n) in the worst case
 * - Traversals: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function prototypes
Node* createNode(int data);
Node* insert(Node* root, int data);
Node* deleteNode(Node* root, int data);
Node* search(Node* root, int data);
Node* findMax(Node* root);
Node* findMin(Node* root);
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);
void freeTree(Node* root);

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n*** BST Menu ***\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. FindMax\n");
        printf("5. FindMin\n");
        printf("6. Pre-order Traversal\n");
        printf("7. In-order Traversal\n");
        printf("8. Post-order Traversal\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &data);
                Node* found = search(root, data);
                if (found)
                    printf("Value %d found in the BST.\n", data);
                else
                    printf("Value %d not found in the BST.\n", data);
                break;
            case 4:
                {
                    Node* maxNode = findMax(root);
                    if (maxNode)
                        printf("Maximum value in the BST is %d.\n", maxNode->data);
                    else
                        printf("The BST is empty.\n");
                }
                break;
            case 5:
                {
                    Node* minNode = findMin(root);
                    if (minNode)
                        printf("Minimum value in the BST is %d.\n", minNode->data);
                    else
                        printf("The BST is empty.\n");
                }
                break;
            case 6:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 7:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 8:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 9:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

Node* findMax(Node* root) {
    Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

Node* findMin(Node* root) {
    Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Pre-order traversal of the BST
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
