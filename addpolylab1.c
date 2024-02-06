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
struct node *add(struct node *head1, struct node *head2);

int main()
{
    struct node *head1 = NULL, *head2 = NULL, *result = NULL;

    printf("Enter first polynomial:\n");
    head1 = create(head1);

    printf("\nEnter second polynomial:\n");
    head2 = create(head2);

    printf("\nDisplaying the 1st polynomial:\n");
    display(head1);

    printf("\nDisplaying the 2nd polynomial:\n");
    display(head2);

    result = add(head1, head2);

    printf("\nResult of addition:\n");
    display(result);

    return 0;
}

struct node *create(struct node *head)
{
    int n, i, coef, exp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%d", &coef);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);
        head = addnode(head, coef, exp);
    }

    return head;
}

struct node *addnode(struct node *head, int coef, int exp)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->next = NULL;

    if (head == NULL )
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL && exp <= ptr->next->exp)
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
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coef, temp->exp);
        if (temp->next != NULL)
        {
            printf("+ ");
        }
      temp = temp->next;
    }

    printf("\n");
}

struct node *add(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *current1 = head1;
    struct node *current2 = head2;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->exp == current2->exp)
        {
            result = addnode(result, current1->coef + current2->coef, current1->exp);
            current1 = current1->next;
            current2 = current2->next;
        }
        else if (current1->exp > current2->exp)
        {
            result = addnode(result, current1->coef, current1->exp);
            current1 = current1->next;
        }
        else
        {
            result = addnode(result, current2->coef, current2->exp);
            current2 = current2->next;
        }
    }

    while (current1 != NULL)
    {
        result = addnode(result, current1->coef, current1->exp);
        current1 = current1->next;
    }

    while (current2 != NULL)
    {
        result = addnode(result, current2->coef, current2->exp);
        current2 = current2->next;
    }

    return result;
}
