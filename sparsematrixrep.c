#include<stdio.h>
void main()
{
    int a[3][3];
    int i,j;
    printf("enter the elements of the matrix:-- ");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
printf("the elements of the matrix:-- ");
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            printf("%d\t",a[i][j]);
        }
    }
    int nz=0,z=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]!=0)
            {
                nz++;
            }
            else {
                z++;
            }
        }
    }
    if(nz>z)
    {
         printf("\n It is not a sparse matrix");
    }
    else if(z>nz)
    {
        int s[nz][3],k=0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(a[i][j]!=0)
                {
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=a[i][j];
                k++;
                }
            }
        }
        printf("\n The sparse matrix is :-- ");
        for(i=0;i<nz;i++)
        {
            printf("\n");
            for(j=0;j<3;j++)
            {
                printf("%d\t",s[i][j]);
            }
        }
    }

}

