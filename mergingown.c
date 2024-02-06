#include<stdio.h>
#include<stdlib.h>
int sort(int a[],int s)
{
    int i,j,temp;
    for(i=0;i<s;i++)
    {
        for(j=0;j<s-1-i;j++)
        {
            if(a[j+1]>a[j])
            {
                 temp=a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;
            }
        }
    }
    return 0;
}
void main()
{
    int i,j,*p,*q,*r,n,m;
    printf("enter the size of array1&array2 u want:--- ");
    scanf("%d",&n);
    scanf("%d",&m);
    p=(int*)malloc(n*sizeof(int));
    q=(int*)malloc(m*sizeof(int));
    printf("\nenter array elements in array 1:-- ");
    for(i=0;i<n;i++)
    {
        scanf("%d\t",&p[i]);
    }
     printf("\nenter array elements in array 2:-- ");
     for(i=0;i<m;i++)
     {
        scanf("%d\t",&q[i]);
     }
     sort(p,n);
     sort(q,m);
     r=(int*)malloc((m+n)*sizeof(int));
     int k=0;
     while(i<n&&j<m)
     {
        if(p[i]<q[j])
        {
            r[k]=p[i];
            i++;
            k++; 
        }
        else if(p[i]==q[i])
        {
            r[k]=p[i];
            i++;
            j++;
            k++;
        }
        else if(p[i]>q[i])
        {
            r[k]=q[j];
            j++;
            k++;

        }

     }
     while(i<n)
     {
           r[k]=p[i];
           i++;
           k++;
     }
     while(j<m)
     {
        r[k]=q[j];
        j++;
        k++;
     }
     printf("The merged and the sorted array is :-- ");
     for(i=0;i<m+n;i++)
     {
        printf("%d\t",&r[i]);
     }

}



