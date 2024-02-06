/*22051031 Sourav DSLab */
#include<stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int deg;
    struct node *next;
}*head=NULL;

void create()
{
    struct node *newnode,*last;
    last=NULL;
     int n,i;
     printf("enter no of terms:-- ");
     scanf("%d",&n);
     printf("\nenter each term with coef &degree:-- ");
     for(i=0;i<n;i++)
     {
         newnode=(struct node*)malloc(sizeof(struct node));
         scanf("%d%d",&newnode->coef,&newnode->deg);
         newnode->next=NULL;
         if(head==NULL)
         {
            head=last=newnode;
         }
         else{
            last->next=newnode;
            last=newnode;
         }
     }


}
void display()
{
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%dx^%d",ptr->coef,ptr->deg);
        if(ptr->next!=NULL)
        {
            printf("+");
        }
        else
        {
            printf("");
        }
        ptr=ptr->next;
    }
}
int main()
{
    int choice;
    do{
    printf("\nMain Menu");
    printf("\nClick 1 to ceate a polynomial:- ");
    printf("\nClick 2 to display the polynomial:- ");
     printf("\nClick 3 to exit:- ");
    printf("\nenter ur choice:-- ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:create();
        break;
        case 2:display();
        break;
        case 3:return 0;
    }}while(choice!=3);
    
    return 0;
}
