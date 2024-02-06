#include<stdio.h>
#include<stdlib.h>
int bbsort(int a[],int m)
{
    int temp;
    int i,j;
    for( i=0;i<m-1;i++)
    {
        for( j=0;j<m-i-1;j++)
        {
              if(a[j]>a[j+1])
              {
                      temp=a[j];
                      a[j]=a[j+1];
                      a[j+1]=temp;
              }
        }
    }
    printf("\n sorted array =");
    for(i=0;i<m;i++)
    {
        printf("%d\t",a[i]);
        printf("\n");
    
    }
    return 0;
}
void main()
{
int *ptr,n;
printf("enter the size of array u want:---  ");
scanf("%d",&n);
ptr=(int*)malloc(n*sizeof(int));
for(int i=0;i<n-1;i++)
{
    scanf("%d\t",&ptr[i]);
}
bbsort(ptr,n);
}
