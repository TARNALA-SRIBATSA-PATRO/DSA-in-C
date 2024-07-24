/*
 * Filename: linear_search.c
 * Description: This program implements the Linear Search algorithm to find an element in an array of integers.
 * Author: Tarnala Sribatsa Patro
 * Date: 24-07-2024
 * Compilation: gcc -o linear_search linear_search.c
 * Execution: ./linear_search
 *
 * Linear Search Algorithm:
 * 1. Start from the first element of the array and compare it with the element to search for.
 * 2. If a match is found, return the index of the element.
 * 3. If no match is found by the end of the array, return -1 to indicate the element is not present.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int linear_search(int arr[], int n, int element) { // Function to perform Linear Search
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i; // Element found, return index
        }
    }

    return -1; // Element not found, return -1
}

int main() {
    int arr[100], n, element, result, i;

    printf("Enter the Array Size: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &element);

    result = linear_search(arr, n, element); // Call the function

    if (result != -1) {
        printf("Element %d found at index %d.\n", element, result);
    } else {
        printf("Element %d not found in the array.\n", element);
    }

    return 0;
}
