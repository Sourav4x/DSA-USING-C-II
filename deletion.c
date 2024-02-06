#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *p,ele,loc,n;
    printf("enter the size of the array :-- ");
    scanf("%d",&n);
    p=(int*)malloc((n+1) * sizeof(int));
    printf("\nenter the array elemets :- ");
    for(int i=0;i<n;i++)
    {
         scanf("%d",&p[i]);
    }
    printf("\nenter the position u want to delete :-");
    scanf("%d",&loc);
    int item;
    item=p[loc];
    for(int i=loc;i<n-1;i++)
    {
        p[i]=p[i+1];
    }
    printf("the array now is :-");
    for(int i=0;i<n-1;i++)
    {
        printf("%d\t",p[i]);
    }
}