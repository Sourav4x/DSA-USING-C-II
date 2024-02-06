
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev,*next;
}*head;

void create(int n)
{
    struct node *temp,*newnode;
    int data,i;
    head=(struct node*)malloc(sizeof(struct node));
    if(n>0)
    printf("enter the data in 1st node :--- ");
    scanf("%d",&data);
    head->data=data;
    head->prev=head;
    head->next=head;
    temp=head;
    for(i=2;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data in node %d:-- ",i);
        scanf("%d",&data);

        newnode->data=data;
        newnode->next=head;
        newnode->prev=temp;
        temp->next=newnode;
        temp=temp->next;
        temp=newnode;
    }
    printf("\n Linked List created");
}
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=head)
    {
        printf("Data :- %d\n",temp);
        temp=temp->next;
    }
}

int checkloophere()
{
    struct node *f,*s;
    f=s=head;
    do{
        s=s->next;
        f=f->next;
        f=f!=NULL?f=f->next:f;
    }while(f&&s!=NULL && f!=s);
    if(f==s)
    {
        return 1;
    }
    else{
        return 0;
    }


}


int main()
{
    int z,v;
    int n;
    printf("enter the number of nodes in ur linked list:-- ");
    scanf("%d",&n);
    create(n);
    display();
    printf("\n Check loop here press 1 for that:-- ");
    scanf("%d",&z);
    if(z==1)
    {
       v=checkloophere();

    }
    else{
        printf("\nInvalid input given");
    }
    if(v==1)
    {
        printf("\nLOOP is present");
    }
    else{
        printf("\n Loop is  not present");
    }
}