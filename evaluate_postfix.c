/*
 * Filename: evaluate_postfix.c
 * Description: This program evaluates an arithmetic expression written in postfix notation using a stack.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o evaluate_postfix evaluate_postfix.c
 * Execution: ./evaluate_postfix
 *
 * Postfix Evaluation Algorithm:
 * 1. Initialize the stack.
 * 2. Read the postfix expression character by character.
 * 3. If the character is an operand, push it onto the stack.
 * 4. If the character is an operator, pop two elements from the stack, apply the operator, and push the result back onto the stack.
 * 5. At the end of the expression, the value on the top of the stack is the result of the expression.
 *
 * Time Complexity: O(n) where n is the length of the postfix expression
 * Space Complexity: O(n) where n is the length of the postfix expression
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

// Global declarations
int stack[SIZE];
int top = -1;

// Function prototypes
void push(int);
int pop();
int evaluate(char *);

int main() {
    char expression[SIZE];

    printf("Enter a postfix expression: ");
    fgets(expression, SIZE, stdin);

    int result = evaluate(expression);

    printf("Result of the postfix expression: %d\n", result);

    return 0;
}

void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push any more elements.\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return -1; 
    } else {
        return stack[top--];
    }
}

int evaluate(char *expression) {
    for (int i = 0; expression[i] != '\0' && expression[i] != '\n'; i++) {
        if (isdigit(expression[i])) {
            // Convert the character to an integer and push it onto the stack
            push(expression[i] - '0');
        } else if (expression[i] == ' ') {
            // Skip spaces in the expression
            continue;
        } else {
            // Pop two operands from the stack
            int operand2 = pop();
            int operand1 = pop();

            // Perform the operation and push the result back onto the stack
            switch (expression[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", expression[i]);
                    exit(1);
            }
        }
    }

    // The result of the expression is the only element left in the stack
    return pop();
}
