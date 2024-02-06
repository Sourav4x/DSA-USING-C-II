#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, c, s = 0, n, j;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *ptr;
    ptr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements in the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    for (i = 0; i < n; i++) {
        c = 0; // Reset the divisor count for each element
        for (j = 1; j <= ptr[i]; j++) {
            if (ptr[i] % j == 0) {
                c++;
            }
        }
        if (c == 2) {
            s += ptr[i];
        }
    }

    printf("The sum of all the prime elements in the array is: %d\n", s);

    free(ptr); // Don't forget to free the allocated memory
    return 0;
}
