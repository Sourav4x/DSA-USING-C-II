#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
}* top=NULL;

void push(int y)
{
    struct node  *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nour Stack is full");
    }
    else{
        newnode->next=top;
        newnode->data=y;
        top=newnode;
    }
}
int pop()
{
    int x;
    struct node *ptr;
    if(top==NULL)
    {
        printf("\n Our stack is empty");
    }
    else{
        ptr=top;
        top=top->next;
        x=ptr->data;
        free(ptr);
    }
    return x;
}
void display()
{
    struct node *temp;
    temp=top;
    while(temp!=NULL)
    {
        printf("\n%d\n",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int peek()
{
    if(top!=NULL)
    {
        return top->data;
    }
    else 
    {
        return -1;
    }
}
int main()
{
  int choice,val;
  do{
        printf("\nMAIN MENU");
        printf("\n1)Display the prog");
        printf("\n 2)To push an element in Our Stack");
        printf("\n 3)Pop Operation");
        printf("\n 4)Peek operation");
        printf("\n 5) exit");
        printf("\n Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("displaying the stack:-- ");
            display();
            break;

           case 2: printf("\n Enter the number to be pushed in stack :");
               scanf("%d",&val);
               push(val);
               break;

            case 3: val=pop();
                printf("\nthe number deleted in the stack is %d",val);
               printf("\ndisplaying the stack now:-\n");
               display();
               break;
            case 4:val=peek();
                printf("the value stored in the top of our stack is :-- %d",val);
               break;
            case 5: 
              return -1;
        }

        }while(choice!=5);
        return 0;

}