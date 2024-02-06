#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

double findMedian(int arr[], int n) {
    // Sort the array in ascending order
    qsort(arr, n, sizeof(int), compare);

    // Check if the array has an odd or even number of elements
    if (n % 2 == 1) {
        // Odd number of elements, return the middle element
        return (double)arr[n / 2];
    } else {
        // Even number of elements, return the average of the two middle elements
        int middle1 = arr[(n - 1) / 2];
        int middle2 = arr[n / 2];
        return (double)(middle1 + middle2) / 2.0;
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    double median = findMedian(arr, n);
    printf("Median of the array is: %.2lf\n", median);

    return 0;
}
