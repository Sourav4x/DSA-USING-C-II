#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,c,s=0,n,j;
    printf("enter the number of elements in the array : -- ");
    scanf("%d",&n);
    int *ptr;
    ptr=(int*)malloc(n* sizeof(int));
    printf("\n enter the elements in the array :-- ");
    for(i=0;i<n;i++)
    {
    scanf("%d",&ptr[i]);
    }
    for(i=0;i<n;i++)
    {
        c=0;
        for(j=1;j<=ptr[i];j++)
        {
        if(ptr[i]%j==0)
        {
            c++;
        }
    }
    if(c==2)
    {
        s=s+ptr[i];
    }
    }
    printf("\nthe sum of all the prime elements in the array is :- %d",s);
    free(ptr);
    return 0;
}
