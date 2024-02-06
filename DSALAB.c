/*SOURAV 22051031 ASG*/
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
    else{
        printf("\nthe no of nodes must be greater than 0");
    }
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
    struct node *ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    ptr=NULL;

}
void delend()
{
    struct node *ptr,*prev;
    prev=NULL;
    ptr=head;
    while(ptr->next)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=NULL;
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
     
    while(cur->next!=NULL)
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
int nonodes()
{
    struct node *ptr;
     int c=0;
    ptr=head;
    while(ptr!=0)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}
void add(int k)
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        ptr->data=ptr->data+k;
        ptr=ptr->next;
    }
}
void interchange(int k)
{
    struct node *ptr,*prev;
    prev=NULL;
    ptr=head;
    int temp,i=0;
    while(i<k-1 && ptr!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
        i++;
    }
temp=ptr->data;
ptr->data=ptr->next->data;
ptr->next->data=temp;

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
    printf("\n Enter 9 to delete the key\n");
    printf("\n Enter 10 to count total number of nodes\n");
    printf("\nenter 11 to search element in a linked list\n");
    printf("\nclick 12 to add an element K to every data:- \n ");
    printf("\nEnter 12 to exit from the list\n");
    printf("\n click 13 to interchange elements") ;
    printf("\nclick 14 to exit");
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
       printf("\nenter the element :- \n");
       scanf("%d",&ele);
       delele(ele);
       printf("\n Now the data in the list becomes\n");
       displayList();
       break;
       case 10:
        z=nonodes();
        printf("\nNo of nodes are %d\n",z);
       break;
       case 11:
       printf("\nenter the element :- \n");
       scanf("%d",&ele);
          int index = search(ele);
          if(index==1)
          {
            printf("the element is present");
          }
          else if(index==0)
          {
            printf("\nthe element is absent from the list");
          }
          case 12:
          printf("\nenter the element k:-  \n");
          scanf("%d",&ele);
          add(ele);
          displayList();
          break;

          case 13:
          printf("\n enter the Kth elements to be interchanged:-- ");
          scanf("%d",&ele);
               interchange(ele);
               displayList();
               break;
        case 14:
        return -1;

    }

    
    }while(choice!=15);

    return 0;
}

