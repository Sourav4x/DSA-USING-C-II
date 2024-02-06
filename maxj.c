#include <stdio.h>
#include<stdlib.h>
int maxIndexDiff(int arr[], int n) {
    int maxDiff = -1;

    // Create two auxiliary arrays for the minimum value to the left
    // and the maximum value to the right of each element.
    int *leftMin = (int *)malloc(sizeof(int) * n);
    int *rightMax = (int *)malloc(sizeof(int) * n);

    // Fill the leftMin array
    leftMin[0] = arr[0];
    for (int i = 1; i < n; i++) {
        leftMin[i] = (arr[i] < leftMin[i - 1]) ? arr[i] : leftMin[i - 1];
    }

    // Fill the rightMax array
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = (arr[i] > rightMax[i + 1]) ? arr[i] : rightMax[i + 1];
    }

    // Traverse both arrays to find the maximum difference j - i
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (leftMin[i] < rightMax[j]) {
            maxDiff = (j - i > maxDiff) ? j - i : maxDiff;
            j++;
        } else {
            i++;
        }
    }

    // Free allocated memory
    free(leftMin);
    free(rightMax);

    return maxDiff;
}

int main() {
    int arr[] = {9, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxIndexDiff(arr, n);
    
    if (result != -1) {
        printf("Maximum j - i such that arr[j] > arr[i]: %d\n", result);
    } else {
        printf("No such pair exists.\n");
    }

    return 0;
}
