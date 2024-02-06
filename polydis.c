/*sourav 22051031*/
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
void display(struct node *head);

int main()
{
    struct node *head1, *head2;
    head1 = NULL;
    printf("\nEnter first polynomial: ");
    head1 = create(head1);
    return 0;
    display(head1);
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

void display(struct node *head)
{
    struct node *temp;
    temp = head; 

    while (temp != NULL)
    {
        if (temp->exp == 0)
        {
            printf("%d", temp->coef); 
        }
        else
        {
            printf("(%dx^%d)", temp->coef, temp->exp);
        }
        temp = temp->next;
        if (temp != NULL)
        {
            printf("+");
        }
    }
    printf("\n");
}
