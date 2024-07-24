/*
 * Filename: sparse_matrix_triplet.c
 * Description: This program converts a sparse matrix into its trip representation.
 * Author: Tarnala Sribatsa Patro
 * Date: 24-07-2024
 * Compilation: gcc -o sparse_matrix_triplet sparse_matrix_triplet.c
 * Execution: ./sparse_matrix_triplet
 *
 * Trip Representation Algorithm:
 * 1. Read the size of the matrix (row and col).
 * 2. Read the matrix elements from the user.
 * 3. Traverse the matrix and for each non-zero element, add its row index, column index, and value to the trip.
 * 4. Print the trips.
 *
 * Time Complexity: O(row * col) where row is the number of rows and col is the number of columns
 * Space Complexity: O(k) where k is the number of non-zero elements
 */

#include <stdio.h>

#define SIZE 100

void print_trip(int trip[][3], int k) {
    int i;
    printf("Trip Representation (row, column, value):\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", trip[i][0], trip[i][1], trip[i][2]);
    }
}

int main() {
    int row, col, matrix[SIZE][SIZE], trip[SIZE * SIZE][3];
    int i, j, k = 0;

    printf("Enter the size of the matrix (row and col): ");
    scanf("%d %d", &row, &col);

    printf("Enter the matrix elements:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Find non-zero elements and add them to the trip
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                trip[k][0] = i;
                trip[k][1] = j;
                trip[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    print_trip(trip, k);

    return 0;
}
