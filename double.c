#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node *prev,*next; 
}*head;
int n;
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if(n>0)
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data; 
        head->next =head; 
        head->prev =head;
    
        

        temp = head;
    
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next =head; 
                newNode->prev=temp;
                temp->next=newNode;
                temp=newNode;
            }
             printf("linked list created\n");
    
        
    }
    else{
        printf("\nthe no of nodes must be greater than 0");
    }
}




void displayList()
{
    struct node *temp;
    temp=head;
 do
 {
    printf("%d\n",temp->data);
      temp=temp->next;
 }while(temp!=head);
 
 }

void deleteany()
{
    struct node *temp;
    struct node *prev,*cur;
    int ps,x,i;
    cur=head;
    prev=head;
    printf("\nenter the postion u want to delete\n");
    scanf("%d",&ps);
    for(i=0;i<ps-1;i++)
    {
        cur=cur->next;
    }
    cur->prev->next=cur->next;
    if(cur->next)
    {
       cur->next->prev=cur->prev;
       x=cur->data;
    }
    free(cur);
}
void insertbeg()
{
    struct node *newnode,*temp,*ptr;
    int data;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data in the new node :-- ");
    scanf("%d",&data);
    newnode->data=data;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}
void insertend()
{
     struct node *newnode,*ptr;
    int data;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data in the new node :-- ");
    scanf("%d",&data);
    newnode->data=data;
    ptr=head;
    while(ptr->next!=head)
    {
       ptr=ptr->next;
    
    }
    ptr->next=newnode;
    newnode->prev=ptr;
    head->prev=newnode;
    newnode->next=head;
}
void insertmiddle()
{
    struct node *newnode;
    struct node *ptr;
    int data,pos;
    newnode=(struct node*)malloc(sizeof(struct node));
ptr=head;
printf("\nenter the position u want to enter:-- ");
scanf("%d",&pos);
 printf("\nenter data in the new node :-- ");
    scanf("%d",&data);
    newnode->data=data;
    pos--;
    while(pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }
    newnode->next=ptr->next;
    newnode->prev=ptr;
    ptr->next->prev=newnode;
    ptr->next=newnode;
}
int empty()
{
    if(head==NULL)
    {
        printf("\n it is empty");
    }
    else 
    {
        printf("it is not empty");
    }
    return 0;
}
void delbeg()
{
    struct node *ptr,*adr;
    int x;
    ptr=head;
    adr=head->prev;
    if (head->next == head) 
    {

        head = NULL;
    }else
    {
     head=head->next;
    head->prev=adr;
     adr->next=head;
    }
    free(ptr);
    }



void dellast()
{
    struct node *ptr;
    ptr=head->prev;
    if(ptr=head)
    {
        head=NULL;

    }else{

    
    ptr->prev->next=head;
    head->prev=ptr->prev;
    }
    free(ptr);
}

 int main()
{
    int choice,pos,ele,z;

    
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    if(n>0)
    {
    createList(n);
    }
do{
    
    printf("\nPress 1 to traverse the linked list\n");
    printf("\npress 2 to check if it is empty or not\n");
    printf("\npress 3 enter new node at the beginning\n");
    printf("\n enter 4 to insert at the end\n");
    printf("\nENTER 5 to insert at a particular position\n");
    printf("\n enter 6 to delete node at the beginning\n");
     printf("\n Enter 7 Delete node at any position\n");
     printf("\n Enter 8 Delete node at the end\n");
    printf("\nEnter 9 to exit from the list\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
         printf("\nData in the list\n");
    displayList();
    break;

    case 2:
        empty();
    break;
    case 3:
    insertbeg();
    printf("\nData in the list\n");
    displayList();
    break;


    
    case 4:
    insertend();
    printf("\n DATA in the list\n");
    displayList();
    break;
    case 5:
    insertmiddle();
    printf("\n DATA in the list\n");
    displayList();
    break;

    case 6:
    delbeg();
    printf("\nNow the  Data in the list becomes\n");
    displayList();
     break;
       case 7:
       deleteany();
       printf("\n Now the data in the list becomes\n");
       displayList();
       break;
       case 8 :
       dellast();
       printf("\n Now the data in the list become\n");
       displayList();
       break;
          case 9:

          return -1;

    }

    
    }while(choice!=10);

    return 0;
}

