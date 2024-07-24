/*
 * Filename: insertion_sort.c
 * Description: This program implements the Insertion Sort algorithm to sort an array of integers in ascending order.
 * Author: Tarnala Sribatsa Patro
 * Date: 2024-07-24
 * Compilation: gcc -o insertion_sort insertion_sort.c
 * Execution: ./insertion_sort
 *
 * Insertion Sort Algorithm:
 * 1. Start from the second element of the array (assuming the first element is already sorted).
 * 2. Compare the current element with the elements before it.
 * 3. Shift all larger elements one position to the right.
 * 4. Insert the current element into its correct position.
 * 5. Repeat the process for all elements in the array.
 *
 * Time Complexity: O(n^2) in the average and worst case; O(n) in the best case (when the array is already sorted)
 * Space Complexity: O(1)
 */

#include <stdio.h>

void insertion_sort(int arr[], int n) { // Function to sort the array
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertion_sort(arr, n); // Call the function

    printf("After Sorting the Array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");

    return 0;
}
