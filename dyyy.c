#include <stdio.h>
#include <stdlib.h>

int main() {
    int **arr;
    int m, n;
    int i, j;

    printf("\nEnter the size of your array (m x n): ");
    scanf("%d %d", &m, &n);

    // Allocate memory for the 2D array
    arr = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    // Input elements
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Display the elements of the matrix
    printf("The elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    int nz = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                nz++;
            }
        }
    }

    if (nz > (m * n) / 2) {
        printf("\nIt is not a sparse matrix\n");
    } else {
        // Allocate memory for the sparse matrix representation
        int **s = (int **)malloc((nz + 1) * sizeof(int *));
        for (i = 0; i < nz + 1; i++) {
            s[i] = (int *)malloc(4 * sizeof(int)); // Four columns (row, column, value, size info)
        }

        // Fill the first row with size information
        s[0][0] = m;
        s[0][1] = n;
        s[0][2] = nz;

        int k = 1; // Start filling from the second row
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (arr[i][j] != 0) {
                    s[k][0] = i;
                    s[k][1] = j;
                    s[k][2] = arr[i][j];
                    k++;
                }
            }
        }

        // Display the sparse matrix
        printf("\nThe sparse matrix is:\n");
        for (i = 0; i < nz + 1; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d\t", s[i][j]);
            }
            printf("\n");
        }

        // Free allocated memory for s
        for (i = 0; i < nz + 1; i++) {
            free(s[i]);
        }
        free(s);
    }

    // Free allocated memory for arr
    for (i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
