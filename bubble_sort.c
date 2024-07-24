/*
 * Filename: bubble_sort.c
 * Description: This program implements the Bubble Sort algorithm to sort an array of integers in ascending order.
 * Author: Tarnala Sribatsa Patro
 * Date: 2024-07-24
 * Compilation: gcc -o bubble_sort bubble_sort.c
 * Execution: ./bubble_sort
 */

#include <stdio.h>

void bubble_sort(int arr[], int as) { // Function to sort the array
    int i, j, temp;

    for (i = 0; i < as-1; i++) {
        for (j = 0; j < as-i-1; j++) {
            if (arr[j] > arr[j+1]) { // Swap if the condition satisfies
                temp = arr[j]; 
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[100], as, i;

    printf("Enter the Array Size: ");
    scanf("%d", &as);

    printf("Enter %d elements:\n", as);
    for (i = 0; i < as; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, as); // Call the function

    printf("After Sorting the Array: ");
    for (i = 0; i < as; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\n");

    return 0;
}
