#include<stdio.h>
void main()
{
    int a[10];
    int l,c=0;
    l=a[0];
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<10;i++)
    {
        if(l<a[i])
        {
            l=a[i];
        }
    }
    for(int i=0;i<10;i++)
    {
        if(l==a[i])
        {
            c++;
        }
    }
    printf("the largest number of the array is %d and it appears %d times in this array",l,c);
}
