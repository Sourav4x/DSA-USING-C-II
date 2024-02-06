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
    printf("\nenter the position u want to enter :-");
    scanf("%d",&loc);
    printf("\nenter the element you want to enter :-");
    scanf("%d",&ele);
    for(int i=n;i>=loc;i--)
    {
        p[i+1]=p[i];
    }
    p[loc]=ele;
    printf("Now the array is :-- ");
    for(int i=0;i<n+1;i++)
    {
        printf("%d\t",p[i]);
    }


}