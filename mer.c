#include <stdio.h> 
#include <stdlib.h> 
int* sort(int arr[], int n) 
{ 
    int i,j,temp; 
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<n-i-1;j++) 
        { 
            if(arr[j]>arr[j+1]) 
            { 
                temp = arr[j]; 
                arr[j]=arr[j+1]; 
                arr[j+1]=temp; 
            } 
        } 
    } 
    return arr; 
} 
int main() 
{ 
    int n1,n2,i, *a,*b,*c; 
    printf("Enter size of array 1: "); 
    scanf("%d",&n1); 
    printf("Enter size of array 2: "); 
    scanf("%d",&n2); 
    a = (int*)malloc(n1*sizeof(int)); 
    b = (int*)malloc(n2*sizeof(int)); 
    int n3 = n1+n2; 
    c = (int*)malloc(n3*sizeof(int)); 
    printf("Enter elements of array 1: "); 
    for(i = 0;i<n1;i++) 
    { 
        scanf("%d",&a[i]); 
    } 
    printf("Enter elements of array 2: "); 
    for(i = 0;i<n2;i++) 
    { 
        scanf("%d",&b[i]); 
    } 
    a = sort(a,n1); 
    b = sort(b,n2); 
    int j=0,k=0; 
    i = 0; 
    while(i<n1 && j<n2) 
    { 
        if (a[i]<=b[j]) 
        { 
            c[k]=a[i]; 
            k++; 
            i++; 
        } 
        else 
        { 
            c[k]=b[j]; 
            k++; 
            j++; 
        } 
    } 
    printf("\nElements of merged & sorted array: "); 
    for(i = 0;i<n3;i++) 
        printf("%d ",c[i]); 

    return 0; 
}