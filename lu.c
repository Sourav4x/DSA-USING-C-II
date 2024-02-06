#include<stdio.h> 


int main() 
{ 
   int i, j;
    int row,column;
    printf("Enter rows\n");
    scanf("%d", &row);
    
    printf("Enter columns\n");
    scanf("%d", &column);
    
    
  int matrix[row][column];
  printf("\nEnter the elements of the matrix:\n");
  for(i=0;i<row;i++)
  {
    for(j=0;j<column;j++)
    {
      scanf("%d", &matrix[i][j]);
	  
    }
  }
 printf("\n");
  
  printf("Lower triangular matrix: \n") ; 
  for(i = 0; i < row; i++) 
  { 
    for (j = 0; j < column; j++) 
    { 
      if (i < j) 
      { 
       printf("0  "); 
      } 
      else
      printf("%d  ", matrix[i][j]);
      
    } 
    printf("\n"); 
  } 
  
  
  printf("Upper triangular matrix: \n");
  for (i = 0; i < row; i++) 
  { 
    for (j = 0; j < column; j++) 
    { 
      if (i > j) 
      { 
        printf("0  "); 
		
      } 
      else
      printf("%d  ", matrix[i][j]);
    } 
    printf("\n"); 
  }  
  return 0; 
}