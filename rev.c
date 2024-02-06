//Q2 solution
#include<stdio.h>
void main()

{
    int a[10],i,n;
    printf("enter the no of elements of the array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int temp=0;
    int d=n-1;
    printf("the reversed array is");
    for(i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[d];
        a[d]=temp;
        d--;
    }
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }


}