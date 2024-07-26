/*
 * Filename: heap_sort.c
 * Description: This program implements the Heap Sort algorithm for sorting an array of integers.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o heap_sort heap_sort.c
 * Execution: ./heap_sort
 *
 * Heap Sort Algorithm:
 * 1. Build a max heap from the input data.
 * 2. Extract elements one by one from the heap and place them at the end of the array.
 * 3. Rebuild the heap for the remaining elements.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

#define SIZE 10

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void printArray(int arr[], int size);

int main() {
    int arr[SIZE], i;
    
    printf("Enter %d integers to sort:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    
    heapSort(arr, SIZE);
    
    printf("Sorted array:\n");
    printArray(arr, SIZE);
    
    return 0;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
