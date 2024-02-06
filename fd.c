#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,*ptr,F;
    printf("Enter array size");
    scanf("%d",&F);
    ptr=(int*)calloc(F,sizeof(int));
    printf("Enter array elements");
    for(i=0;i<F;i++)
        scanf("%d",&ptr[i]);
    printf("Entered array");
    for(i=0;i<F;i++)
        printf("%d\t\n",ptr[i]);
    int r[F];
    for(i=0;i<F;i++)
        r[i]=ptr[i];
    printf("Copied array is:");
    for(i=0;i<F;i++)
        printf("%d\t",r[i]);
    
}