#include <stdio.h>
#include <stdlib.h>

struct node {
    int row;
    int col;
    int val;
    struct node* next;
} * head;

void createnode(int row, int col, int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->row = row;
    newnode->col = col;
    newnode->val = val;
    newnode->next = NULL;

    if (head == NULL) 
    {
        head = newnode;
    } else 
    {
        struct node* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void displayList() {
    struct node* temp = head;
    printf("The tuple format of this sparse matrix is :-- \n");
    while (temp != NULL) 
    {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
}

int main() {
    int r, c;
    printf("Enter the size of the array by row & col: ");
    scanf("%d %d", &r, &c);
    int **a, i, j;
    

    a = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++) {
        a[i] = (int *)malloc(c * sizeof(int));
        for (j = 0; j < c; j++) {
            printf("Enter element at (%d, %d): ", i, j);
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0) {
                createnode(i, j, a[i][j]);
            }
        }
    }


    displayList();

    return 0;
}
