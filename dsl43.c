#include <stdio.h>
#include <stdlib.h>
struct Element {
    int row;
    int col;
    int value;
};
struct SparseMatrix {
    int rows;
    int cols;
};
struct Triplet {
    struct SparseMatrix order;
    int numNonZero;
    struct Element *elements;
};
struct Triplet *createTriplet(int **matrix, int m, int n) {
    struct Triplet *triplet = (struct Triplet *)malloc(sizeof(struct Triplet));
    triplet->order.rows = m;
    triplet->order.cols = n;
    triplet->numNonZero = 0;
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                triplet->numNonZero++;
            }
        }
    }
    triplet->elements = (struct Element *)malloc(triplet->numNonZero * sizeof(struct Element));
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                triplet->elements[index].row = i;
                triplet->elements[index].col = j;
                triplet->elements[index].value = matrix[i][j];
                index++;
            }
        }
    }

    return triplet;
}
void displayTriplet(struct Triplet *triplet)
 {
    printf("Sparse Matrix Triplet Representation:\n");
    printf("Rows: %d, Columns: %d\n", triplet->order.rows, triplet->order.cols);
    printf("Total Non-Zero Elements: %d\n", triplet->numNonZero);
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < triplet->numNonZero; i++)
     {
        printf("%d\t%d\t%d\n", triplet->elements[i].row, triplet->elements[i].col, triplet->elements[i].value);
    }
}

int main()
 {
    int m, n;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) 
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    struct Triplet *triplet = createTriplet(matrix, m, n);
    displayTriplet(triplet);

    return 0;
}
