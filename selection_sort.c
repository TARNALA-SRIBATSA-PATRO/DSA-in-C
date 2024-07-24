/*
 * Filename: selection_sort.c
 * Description: This program implements the Selection Sort algorithm to sort an array of integers in ascending order.
 * Author: Tarnala Sribatsa Patro
 * Date: 2024-07-24
 * Compilation: gcc -o selection_sort selection_sort.c
 * Execution: ./selection_sort
 *
 * Selection Sort Algorithm:
 * 1. Iterate over the array from the start to the end.
 * 2. For each position in the array (i), find the smallest element in the sub-array starting from i.
 * 3. Swap the found smallest element with the element at position i.
 * 4. Repeat the process for the next position until the array is sorted.
 * 
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 */

#include <stdio.h>

void selection_sort(int arr[], int n) { // Function to sort the array
    int i, j, min_idx, temp;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter the Array Size: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, n); // Call the function

    printf("After Sorting the Array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");

    return 0;
}
