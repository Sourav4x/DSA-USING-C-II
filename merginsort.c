//Q1 22051031 sourav
#include<stdio.h>
#include<stdlib.h>

void sort(int X[],int y)
{
	int i,j,c;
	for(i=0;i<y;i++)
	{
		for(j=0;j<y-1-i;j++)
		{
			if(X[j]>X[j+1])
			{
				c=X[j+1];
				X[j+1]=X[j];
				X[j]=c;
			}
		}
	}
}

void accept(int X[],int y)
{
	int i;
	for(i=0;i<y;i++)
	 scanf("%d",&X[i]);
}

void disp(int X[],int y)
{
	int i;
	for(i=0;i<y;i++)
	printf("%d  ",X[i]);
}

int main()
{
	int M,N;
	printf("Enter the size of 1st Array - ");
	scanf("%d",&M);
	printf("Enter the size of the 2nd Array - ");
	scanf("%d",&N);
	
	int *A;
	int *B;
	int *C;
	
	A=(int*)malloc(M*sizeof(int));
	B=(int*)malloc(N*sizeof(int));
	C=(int*)malloc((M+N)*sizeof(int));
	
	printf("\n\nEnter the elements of 1st array\n");
	accept(A,M);
	printf("\n\nEnter the elements of 2nd array\n");
	accept(B,N);
	
	sort(A,M);
	sort(B,N);
	
	int i;
	int j=0,k=0;
	
	for(i=0;i<M+N;i++)
	{
		if(j>=M)
		{
			C[i]=B[k];
			k++;
		}
		else if(k>=N)
		{
			C[i]=A[j];
			j++;
		}
		else if(A[j]<B[k])
		{
			C[i]=A[j];
			j++;
		}
		else
		{
			C[i]=B[k];
			k++;
		}
	}
	
	printf("\n1st Array Sorted - ");
	disp(A,M);
	printf("\n2nd Array Sorted - ");
	disp(B,N);
	printf("\n\nMerged Sorted Array - ");
	disp(C,M+N);
	return 0;
}