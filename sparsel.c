#include<stdio.h>
struct node{
    int row;
    int col;
    int val;
    struct node *next;
}*head;
 createnode(int n,int ar[],int r1,int c1,int ro,int co,int val)
{
    int i,j;
    struct node *temp,*newnode;
    head=(struct node*)malloc(sizeof(struct node));
    if(n>0)
    {
        head->row=r1;
        head->col=c1;
        head->val=n;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++)
        {
          newnode=(struct node*)malloc(sizeof(struct node));
          newnode->row=ro;
          newnode->col=co;
          newnode->val=val;
          newnode->next=NULL;
          temp->next=newnode;
          temp=temp->next;
        }

    }
    displayList(r1,c1,n,ro,co,val);
}
void displayList(int hr,int hc,int hv,int ro,int co,int val)
  {
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d\t %d\t %d\t",temp->row,temp->col,temp->val);
            printf("\n");
            temp = temp->next;                
        }
    }
}

void main()
{
    int r,c,q=0;
    printf("enter the size of the array by row & col:--  ");
    scanf("%d %d",&r,&c);
    int **a,i,j;
    a=(int **)malloc(r *sizeof(int*));
    for(i=0;i<r;i++)
    {
        a[i]=(int*)malloc(c *sizeof(int));
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                q++;
                createnode(q,a,r,c,i,j,a[i][j]);

              
            }
        }
    }
    
}