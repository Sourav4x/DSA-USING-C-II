#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
}*head;
 int main()
{
    int n;

    
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    if(n>0)
    {
    createList(n);


    }
    display();
}
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
                newNode->next = head; 

                temp->next = newNode;
                temp = temp->next;
            }
             printf("linked list created\n");
    }
    }
    void display()
    {
        struct node *ptr;
        ptr=head;
        while(ptr->next!=head)
        {
          printf("data is %d in the list",ptr->data);
            ptr=ptr->next;
        }
    }