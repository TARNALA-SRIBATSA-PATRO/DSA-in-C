/*
 * Filename: check_parentheses.c
 * Description: This program checks the validity of an expression containing nested parentheses using a stack.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o check_parentheses check_parentheses.c
 * Execution: ./check_parentheses
 *
 * Parentheses Validity Algorithm:
 * 1. Initialize the stack.
 * 2. Read the expression character by character.
 * 3. If the character is an opening parenthesis ('(', '{', '['), push it onto the stack.
 * 4. If the character is a closing parenthesis (')', '}', ']'):
 *    a. Check if the stack is empty. If yes, the expression is invalid.
 *    b. Otherwise, pop from the stack and check if it matches the corresponding opening parenthesis.
 * 5. At the end of the expression, if the stack is empty, the expression is valid. Otherwise, it is invalid.
 *
 * Time Complexity: O(n) where n is the length of the expression
 * Space Complexity: O(n) where n is the length of the expression
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Global declarations
char stack[SIZE];
int top = -1;

// Function prototypes
void push(char);
char pop();
int isvalid(char *);

int main() {
    char exp[SIZE];

    printf("Enter an expression with parentheses: ");
    fgets(exp, SIZE, stdin);

    if (isvalid(exp)) {
        printf("The expression is valid.\n");
    } else {
        printf("The expression is invalid.\n");
    }

    return 0;
}

void push(char ch) {
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push any more elements.\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return '\0'; // Return a sentinel value to indicate error
    } else {
        return stack[top--];
    }
}

int isvalid(char *exp) {
    int i;

    for (i = 0; exp[i] != '\0' && exp[i] != '\n'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                return 0; // Stack is empty, so the expression is invalid
            }
            char topElement = pop();
            if ((ch == ')' && topElement != '(') ||
                (ch == '}' && topElement != '{') ||
                (ch == ']' && topElement != '[')) {
                return 0; // Mismatched parentheses
            }
        }
    }

    // If stack is empty at the end, the expression is valid
    return top == -1;
}
