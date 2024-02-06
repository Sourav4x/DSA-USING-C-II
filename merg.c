#include<stdio.h>
#include<stdlib.h>
int sorting(int a[],int n)
{
int i,j,s,min;
for(i=0;i<n-1;i++)
{
     min=i;
    for(j=i+1;j<n;j++)
    {
        if(a[j]<a[min])
        {
            min=j;
        }
    }
}
if(min!=i)
{
    s=a[i];
    a[i]=a[min];
    a[min]=s;
}
return a;

}
int main()
{
    int n,m,*p,*q,*r,k,i;
    printf("enter the size of 1st  array :-   ");
    scanf("%d",&n);
    printf("enter the size of 2nd array:-  ");
    scanf("%d",&m);
    p=(int*)malloc(n*sizeof(int));
    q=(int*)malloc(m*sizeof(int));
    k=m+n;
    r=(int*)malloc(k*sizeof(int));
    printf("enter elements of 1st array:-  ");
    for(i=1;i<n;i++)
    {
        scanf("%d\t",&p[i]);
    }
printf("enter elements of 2nd  array:-  ");
    for(i=0;i<m;i++)
    {
        scanf("%d\t",&q[i]);
    }
    sorting(p,n);
    sorting(q,n);
    int j=0,l=0; 
    i = 0; 
    while(i<n && j<m) 
    { 
        if (p[i]<=q[j]) 
        { 
            r[l]=p[i]; 
            l++; 
            i++; 
        } 
        else 
        { 
            r[l]=q[j]; 
            l++; 
            j++; 
        }
    } 
     printf("\nElements of merged & sorted array: "); 
    for(i = 0;i<k;i++) 
        printf("%d ",r[i]); 
return 0;
}
    
