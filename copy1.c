#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,*l,N;
    printf("Enter the  array size");
    scanf("%d",&N);
    l=(int*)malloc(N*sizeof(int));
    printf("Enter array elements");
    for(i=0;i<N;i++)
        scanf("%d",&l[i]);
    printf("Entered array");
    for(i=0;i<N;i++)
        printf("%d\t\n",LA[i]);
    int LB[N];
    for(i=0;i<N;i++)
        LB[i]=LA[i];
    printf("Copied array is:");
    for(i=0;i<N;i++)
        printf("%d\t",LB[i]);
    return 0;
}