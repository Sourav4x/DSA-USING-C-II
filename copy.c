#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,*LA,N;
    printf("Enter array size");
    scanf("%d",&N);
    printf("Enter array elements:");
    LA=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++)
        scanf("%d",&LA[i]);
    for(i=0;i<N/2;i++)
    {   int c;
        c=LA[i];
        LA[i]=LA[N-i-1];
        LA[N-i-1]=c;
    }
    printf("The reversed array is:\n");
    for(i=0;i<N;i++)
        printf("%d\t",LA[i]);

        return 0;
}