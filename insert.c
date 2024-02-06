//Q6 kode 22051031
#include<stdio.h>
int main()
{
	int r;
	printf("Enter the number of eleements - ");
	scanf("%d",&r);
	int *ptr;
	ptr=(int*)calloc(r,sizeof(int));
	printf("\nEnter the array elements\n");
	int i;
	for(i=0;i<r;i++)
	 scanf("%d",&ptr[i]);
	int j,c;
	for(i=0;i<r;i++)
	{
		for(j=0;j<r-1-i;j++)
		{
			if(ptr[j]>ptr[j+1])
			{
				c=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=c;
			}
		}
	}
	printf("\nSorted Array - ");
	for(i=0;i<r;i++)
	 printf("%d\t",ptr[i]);
	
	int p,m;
	printf("\n\nEnter the element to be inserted - ");
	scanf("%d",&m);
	do
	{
	printf("\nEnter the position where %d should be inserted\nRange for pition = 0 to %d :",m,r-1);
	scanf("%d",&p);
		if(p>=r)
		 printf("\nEnter position within given range");
	}while(p>=r);
	ptr=realloc(ptr,r+1);
	for(i=r+1;i>p;i--)
	 ptr[i]=ptr[i-1];
	ptr[p]=m;
 	printf("\nnew Array -");
 	for(i=0;i<r+1;i++)
	 printf("%d\t",ptr[i]);
}