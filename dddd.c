#include <stdio.h>
#include <stdlib.h>

// Define the size of the matrix (assuming it's square for simplicity)
#define MATRIX_SIZE 4

// Function to calculate the index in a 1D array for lower triangular matrix
int lower_triangular_index(int row, int col) {
    if (row >= col) {
        return row * (row + 1) / 2 + col;
    } else {
        // Handle the case where the element is in the upper triangle
        return -1; // You can use a sentinel value to indicate upper triangle
    }
}

// Function to calculate the index in a 1D array for upper triangular matrix
int upper_triangular_index(int row, int col) {
    if (row <= col) {
        return col * (col + 1) / 2 + row;
    } else {
        // Handle the case where the element is in the lower triangle
        return -1; // You can use a sentinel value to indicate lower triangle
    }
}

int main() {
    int lower_triangular[MATRIX_SIZE * (MATRIX_SIZE + 1) / 2];
    int upper_triangular[MATRIX_SIZE * (MATRIX_SIZE + 1) / 2];

    // Initialize lower triangular matrix
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            int value;
            if (i >= j) {
                // Set values for the lower triangle
                value = i * MATRIX_SIZE + j + 1;
                lower_triangular[lower_triangular_index(i, j)] = value;
            } else {
                // Set sentinel values for the upper triangle
                upper_triangular[upper_triangular_index(i, j)] = -1;
            }
        }
    }

    // Print lower triangular matrix
    printf("Lower Triangular Matrix:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (i >= j) {
                printf("%d ", lower_triangular[lower_triangular_index(i, j)]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    // Print upper triangular matrix
    printf("\nUpper Triangular Matrix:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (i <= j) {
                printf("%d ", upper_triangular[upper_triangular_index(i, j)]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}