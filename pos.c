//asg 6  22051031 sourav
#include <stdio.h>

void insert(int la[], int *s, int v)
 {
    int i = *s - 1;
     while (i >= 0 && la[i] > v)
     {
        la[i + 1] = la[i];
        i--;
    }
    la[i + 1] = v;

    (*s)++;
}

int main()
 {
    int N;
    printf("enter the size of  array: ");
    scanf("%d", &N);

    int la[N]; 
    printf("Enter the elements:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &la[i]);
    }

    int v;
    printf("enter the element to insert: ");
    scanf("%d", &v);

    insert(la, &N, v);

    printf("Array after inserting %d:\n", v);
    for (int i = 0; i < N; i++) {
        printf("%d ", la[i]);
    }

    return 0;
}

