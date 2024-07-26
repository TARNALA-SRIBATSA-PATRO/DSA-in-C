/*
 * Filename: merge_sort.c
 * Description: This program implements the Merge Sort algorithm for sorting an array of integers.
 * Author: Tarnala Sribatsa Patro
 * Date: 26-07-2024
 * Compilation: gcc -o merge_sort merge_sort.c
 * Execution: ./merge_sort
 *
 * Merge Sort Algorithm:
 * 1. Divide the array into two halves.
 * 2. Recursively sort both halves.
 * 3. Merge the two sorted halves to get the final sorted array.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n) due to auxiliary space for merging
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void printArray(int arr[], int size);

int main() {
    int arr[SIZE];
    
    printf("Enter %d integers to sort:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    
    mergeSort(arr, 0, SIZE - 1);
    
    printf("Sorted array:\n");
    printArray(arr, SIZE);
    
    return 0;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int i, j;
    
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    i = 0;
    j = 0;
    int k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
    }
    
    while (j < n2) {
        arr[k++] = R[j++];
    }
    
    free(L);
    free(R);
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
