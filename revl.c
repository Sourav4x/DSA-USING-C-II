/*linked list ops _sourav*/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data; 
    struct node *next; 
}*head;
int main()
{
    int n, choice,pos;

    
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    
    printf("\nPress 1 to reverse the order of singly linked list\n");
    printf("\npress 2 to delete any node\n");
    printf("\npress 3 enter new node at the beginning\n");
    printf("\n enter 4 to insert at the end\n");
    printf("\nENTER 5 to insert at the middle\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        reverseList();
         printf("\nData in the list\n");
    displayList();
    break;

    case 2:
        deleteany();
         printf("\nData in the list\n");
    displayList();
    break;
    case 3:
    insertbeg();
    printf("\nData in the list\n");
    displayList();


    
    case 4:
    insertend();
    printf("\n DATA in the list\n");
    displayList();
    case 5:
    insertmiddle();
    printf("\n DATA in the list\n");
    displayList();
    
    }

    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data; 
        head->next = NULL; 

        temp = head;
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
void reverseList()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; 

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; 

        printf("SUCCESSFULLY REVERSED LIST\n");
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
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                
        }
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
    struct node *newnode;
    int data;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data in the new node :-- ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
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
    newnode->next=NULL;
    ptr=head;
    while(ptr->next!=NULL)
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