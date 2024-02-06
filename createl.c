#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;

void create(int p[],int n)
{
    struct node *newnode,*last;
    int i;
    head=(struct node *)malloc(sizeof(struct node));
    head=p[0];
    head->next=NULL;
    head=last;
    for(i=1;i<n;i++)
    {
       newnode=(struct node*)malloc(sizeof(struct node));
       newnode=p[i];
       newnode->next=NULL;
       last->next=newnode;
       last=newnode;


    }

}
void display()
{
    struct node *ptr;
     ptr=head;
    while(ptr!=NULL)
    {
        printf("the data in the linked list is : %d",ptr->data);
        ptr=ptr->next;
    }
}


int main()
{
    int p[50],n,i;
    printf("enter the size :-- ");
    scanf("%d",&n);
    printf("\nenter all the values:--  ");
    for(i=0;i<n;i++)
    {
        scanf("%d\t",p[i]);
    }
    create(p,n);
    display();

}