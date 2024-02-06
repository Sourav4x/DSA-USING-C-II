#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
}*head1,*head2;


void create(struct node **head,int n)
{
    struct node *newNode, *temp;
    int data, i;

    *head = (struct node *)malloc(sizeof(struct node));
    if(n>0)
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        (*head)->data = data; 
        (*head)->next = NULL; 

        temp = (*head);
    
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL; 

                temp->next = newNode;
                temp = temp->next;
            }
             printf("linked list created\n");
    
        
    }
    else{
        printf("\nthe no of nodes must be greater than 0");
    }
}

int findnode()
{
    int x,c;
    c=0;
    struct node *ptr1,*ptr2;
    ptr1=head1;
    ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
      c++;
      if(ptr1->data!=ptr2->data)
      {
           return c;
      }
      ptr1=ptr1->next;
      ptr2=ptr2->next;
            
    }
    if(ptr2!=NULL)
    {
    return c+1;
    }
}


int main()
{
    int f,n;
    head1=NULL;
    head2=NULL;
    printf("enter 1 to create 1st LL:--  ");
    scanf("%d",&f);
    if(f==1)
    {
        printf("\n enter the number of nodes in ur LL:-- ");
        scanf("%d",&n);
        create(&head1,n);
    }
     printf("\nenter 2 to create 1st LL:--  ");
    scanf("%d",&f);
    if(f==2)
    {
        printf("\n enter those nodes of 1st LL along with an extra node:-- ");
       create(&head2,(n+1));
    }
    int c=findnode();

    printf("\n The extra node in 2nd Linked list is %d",c);
}
