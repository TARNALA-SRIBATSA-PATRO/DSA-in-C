/*
 * Filename: quick_sort.c
 * Description: This program implements the Quick Sort algorithm for sorting an array of integers.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o quick_sort quick_sort.c
 * Execution: ./quick_sort
 *
 * Quick Sort Algorithm:
 * 1. Choose a pivot element from the array.
 * 2. Partition the array into two sub-arrays:
 *    - Elements less than the pivot.
 *    - Elements greater than the pivot.
 * 3. Recursively apply Quick Sort to the sub-arrays.
 * 4. Combine the sorted sub-arrays and pivot to get the final sorted array.
 *
 * Time Complexity:
 * - Average: O(n log n)
 * - Worst-case: O(n^2)
 *
 * Space Complexity: O(log n) due to recursive stack space
 */

#include <stdio.h>

#define SIZE 10

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void printArray(int arr[], int size);

int main() {
    int arr[SIZE], i;
    
    printf("Enter %d integers to sort:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, SIZE - 1);
    
    printf("Sorted array:\n");
    printArray(arr, SIZE);
    
    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1, j;
    
    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    
    return i + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
