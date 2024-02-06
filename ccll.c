/*SOURAV 22051031 ASG CIRCULAR LINKED LIST*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node *next; 
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
        head->next = head; 

        temp = head;
    
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next =temp->next; 

                temp->next = newNode;
                temp = newNode;
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
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        do
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                
        }while(temp!=head);
    }
}
void deleteany()
{
    struct node *temp;
    struct node *prev,*cur;
    int ps;
    cur=head;
    prev=head;
    printf("\nenter the postion u want to delete\n");
    scanf("%d",&ps);
    if(ps== 1)
    {
         head=cur->next;
         free(cur);
         cur=NULL;
    }
    else{
        while(ps!=1)
        {
            prev=cur;
            cur=cur->next;
            ps--;
        }
        prev->next=cur->next;
        free(cur);
        cur==NULL;
    }
}
void insertbeg()
{
    struct node *newnode,*temp;
    int data;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data in the new node :-- ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
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
    newnode->next=head;
    ptr=head;
    while(ptr->next!=head)
    {
       ptr=ptr->next;
    
    }
    ptr->next=newnode;
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
    newnode->next=NULL;
    pos--;
    while(pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }
    newnode->next=ptr->next;
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
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=head->next;
    x=head->data;
    free(head);
    head=ptr->next;

}
void delend()
{
    struct node *ptr,*prev;
    prev=NULL;
    ptr=head;
    while(ptr->next!=head)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=head;
    free(ptr);

}
void delele(int key)
{
  struct node *prev,*cur,*temp;
    head=head->next;
    if(head->data==key)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    else
     {
        cur=head;
     
    while(cur->next!=head)
    {
        if(cur->next->data == key)
        {
          
        temp=cur->next;
        cur->next=cur->next->next;
        free(temp);
        break;
        }
        else{
            cur=cur->next;
        }
    }

}
}
int search(int key)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(key=temp->data)
        return 1;
        temp=temp->next;
    }
    return 0;
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
    printf("\nenter 7 Delete node at the end\n");
     printf("\n Enter 8 Delete node at any position\n");
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
     delend();
     printf("\n Now the data in the list becomes\n");
       displayList();
         break;
       case 8:
       deleteany();
       printf("\n Now the data in the list becomes\n");
       displayList();
       break;
          case 9:

          return -1;

    }

    
    }while(choice!=10);

    return 0;
}

