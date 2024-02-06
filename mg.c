#include <stdio.h>
#include <stdlib.h>

int sort(int a[], int s) {
    int i, j, temp;
    for (i = 0; i < s-1; i++) {
        for (j = 0; j < s - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return 0;
}

int main() {
    int i, *p, *q, *r, n, m;  
    printf("Enter the size of array1: ");  
    scanf("%d", &n);
    printf("Enter the size of array2: ");
    scanf("%d", &m);
    p = (int *)malloc(n * sizeof(int));
    q = (int *)malloc(m * sizeof(int));
    printf("Enter array elements in array 1: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    printf("Enter array elements in array 2: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &q[i]);
    }
    sort(p, n);
     sort(q, m);
    r = (int *)malloc((m + n) * sizeof(int));
    int k = 0, j = 0;  
    i = 0;  
    while (i < n && j < m) {
        if (p[i] < q[j]) {
            r[k] = p[i];
            i++;
            k++;
        } else if (p[i] == q[j]) {  
            r[k] = p[i];
            i++;
         k++; 
         j++;
        } else if (p[i] > q[j]) {  
            r[k] = q[j];
            j++;
            k++;
            
        }
    
    }
    while (i < n) {
        r[k] = p[i];
        i++;
        k++;
    }
    while (j < m) {
        r[k] = q[j];
        j++;
        k++;
    }
    printf("The merged and sorted array is: ");
    for (i = 0; i < m + n; i++)
     {
        {
                  printf("%d ", r[i]);

            
        }
        
    

    
    free(p);
    free(q);
    free(r);

    return 0; 
}
}
