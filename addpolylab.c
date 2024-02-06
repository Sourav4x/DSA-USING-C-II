#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int coef;
    int exp;
};

struct node *create(struct node *head);
struct node *addnode(struct node *head, int coef, int exp);
void mul(struct node *head1, struct node *head2);

int main()
{
    struct node *head1, *head2;
    head1 = head2 = NULL;
    printf("\nEnter first polynomial: ");
    create(head1);
    printf("\nEnter second polynomial: ");
    create(head2);
    printf("\n displaying the 1st polynomial:-- ");
    display(head1);
    printf("\n displaying the 2nd polynomial :--  ");
    display(head2);
    add(head1, head2);
    return 0;
}

struct node *create(struct node *head)
{
    int n, i, coef, exp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nenter coeff in term %d: ", i + 1);
        scanf("%d", &coef);
        printf("enter exponent in term %d: ", i + 1);
        scanf("%d", &exp);
        head = addnode(head, coef, exp);
    }
    return head;
}

struct node *addnode(struct node *head, int coef, int exp)
{
    struct node *ptr;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->next = NULL;
    ptr = head;
    if (head == NULL)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        while (ptr->next != NULL && ptr->next->exp >= exp)
        {
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }

    return head;
}

void add(struct node *head1, struct node *head2)
{
    struct node *ptr1, *ptr2, *head3;
    ptr1 = head1;
    ptr2=head2;
    head3 = NULL;
      int sum;
    while (ptr1 != NULL && ptr2!=NULL)
    {
        if(ptr1->exp==ptr2->exp)
        {
           sum=ptr1->exp+ptr2->exp;
           head3=addnode(head3,sum,ptr1->exp) ;
           ptr1=ptr1->next;
           ptr2-ptr2->next;

        }
        else if(ptr1->exp < ptr2->exp)
         {
          head3=add_node(head3, ptr2->coef, ptr2->exp);
          ptr2=ptr2->next;
         }
     if(ptr1==NULL)
{
  while(ptr2 != NULL)
 {
  head3=add_node(head3, ptr2->coef, ptr2->exp);
  ptr2=ptr2->next;
 }
}

if(ptr2==NULL)
{
  while(ptr1 != NULL)
 {
  head3=add_node(head3, ptr1->coef, ptr1->exp);
  ptr1=ptr1->next;
 }
}

return head3;
}

}
struct node *display(struct node *head)
{
  struct node *ptr;
  ptr=head;

  while(ptr != NULL)
  {

    printf("\n %d x %d \t",ptr->coef,ptr->exp);
    ptr=ptr->next;
  }
  return head;
}
