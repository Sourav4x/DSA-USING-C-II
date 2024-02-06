#include<stdio.h>
#include<stdlib.h>
void sort(int *a,int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
{
    for(j=0;j<n-i-1;j++)
    {
        if(a[j]>a[j+1])
        {
        temp=a[j];
                      a[j]=a[j+1];
                      a[j+1]=temp;
    }
}
}
}
void main()
{
    int *p,*q,*r;
    int i,j,n,m;
printf("enter size of two arrays:--  ");
scanf("%d",&n);
scanf("%d",&m);
    p=(int*)malloc(n* sizeof(int));
    q=(int*)malloc(m* sizeof(int));
    printf("enter array 1 elements:-- ");
for(i=0;i<n;i++)
{
    scanf("%d",&p[i]);
}
printf("\nenter  elements in array 2:--- ");
for(i=0;i<m;i++)
{
    scanf("%d\t",&q[i]);
}
sort(p,n);
sort(q,m);
r=(int*)malloc((m+n)* sizeof(int));
for(i=0;i<n;i++)
{
    r[i]=p[i];
}
for(i=0,j=m;j<m+n-i && i<m;i++,j++)
{
    r[j]=q[i];
}
for(i=0;i<m+n;i++)
{
    printf("%d\t",r[i]);
}
}

