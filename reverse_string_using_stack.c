/*
 * Filename: reverse_string_using_stack.c
 * Description: This program reverses a given string using a stack implemented with an array.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o reverse_string_using_stack reverse_string_using_stack.c
 * Execution: ./reverse_string_using_stack
 *
 * Reverse String Algorithm:
 * 1. Initialize the stack and the top variable.
 * 2. Push each character of the string onto the stack.
 * 3. Pop each character from the stack and store it back in the string.
 * 4. Print the reversed string.
 *
 * Time Complexity: O(n) where n is the length of the string
 * Space Complexity: O(n) where n is the length of the string
 */

#include <stdio.h>
#include <string.h>

#define SIZE 100

// Global declarations
char stack[SIZE];
int top = -1;

// Function prototypes
void push(char);
char pop();
void reverseString(char *);

int main() {
    char str[SIZE];

    printf("Enter a string: ");
    fgets(str, SIZE, stdin);

    reverseString(str);

    printf("Reversed string: %s\n", str);

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
        return '\0';
    } else {
        return stack[top--];
    }
}

void reverseString(char *str) {
    int length = strlen(str);
    int i;

    // Push all characters of the string onto the stack
    for (i = 0; i < length; i++) {
        push(str[i]);
    }

    // Pop all characters from the stack and put them back in the string
    for (i = 0; i < length; i++) {
        str[i] = pop();
    }
}
