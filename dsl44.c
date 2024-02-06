#include <stdio.h>
#include <stdlib.h>

struct Node {
  int row;
  int col;
  int val;
  struct Node *next;
};

struct SparseMatrix {
  int m;
  int n; 
  struct Node *head; 
};

void insert(struct SparseMatrix *spm, int row, int col, int val) {
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->row = row;
  newnode->col = col;
  newnode->val = val;
  newnode->next = spm->head;
  spm->head = newnode;
}

void display(struct SparseMatrix *spm) {
  int row, col;
  for (row = 0; row < spm->m; row++) {
    for (col = 0; col < spm->n; col++) {
      struct Node *current = spm->head;
      while (current != NULL) {
        if (current->row == row && current->col == col) {
          printf("%d ", current->val);
          break;
        }
        current = current->next;
      }
      if (current == NULL) {
        printf("0 ");
      }
    }
    printf("\n");
  }
}


int main() {
  int m, n;
  printf("Enter the number of rows and columns of the sparse matrix: ");
  scanf("%d %d", &m, &n);

  struct SparseMatrix *spm = (struct SparseMatrix *)malloc(sizeof(struct SparseMatrix));
  spm->m = m;
  spm->n = n;
  spm->head = NULL;

  int k;
  printf("Enter the number of non-zero elements in the sparse matrix: ");
  scanf("%d", &k);

  for (int i = 0; i < k; i++) {
    int row, col, val;
    printf("Enter the row, column, and value of the %dth non-zero element: ", i + 1);
    scanf("%d %d %d", &row, &col, &val);

    insert(spm, row, col, val);
  }

  printf("The sparse matrix is:\n");
  display(spm);

  return 0;
}
