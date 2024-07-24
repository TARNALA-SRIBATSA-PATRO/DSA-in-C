/*
 * Filename: binary_search.c
 * Description: This program implements the Binary Search algorithm to find an element in a sorted array of integers.
 * Author: Tarnala Sribatsa Patro
 * Date: 24-07-2024
 * Compilation: gcc -o binary_search binary_search.c
 * Execution: ./binary_search
 *
 * Binary Search Algorithm:
 * 1. Start with the entire array.
 * 2. Find the middle element of the array.
 * 3. If the middle element is equal to the searching element, return its index.
 * 4. If the searching element is less than the middle element, repeat the search on the left sub-array.
 * 5. If the searching element is greater than the middle element, repeat the search on the right sub-array.
 * 6. Continue until the searching element is found or the sub-array size becomes zero.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int binary_search(int arr[], int n, int element) { // Function to perform Binary Search
    int left = 0, right = n - 1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == element) {
            return mid; // Element found, return index
        } else if (arr[mid] < element) {
            left = mid + 1; // Search in the right sub-array
        } else {
            right = mid - 1; // Search in the left sub-array
        }
    }

    return -1; // Element not found, return -1
}

int main() {
    int arr[100], n, element, result, i;

    printf("Enter the Array Size: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &element);

    result = binary_search(arr, n, element); // Call the function

    if (result != -1) {
        printf("Element %d found at index %d.\n", element, result);
    } else {
        printf("Element %d not found in the array.\n", element);
    }

    return 0;
}
