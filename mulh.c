#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL, *poly1 = NULL;

void create(struct Node **poly2);
void Display(struct Node *poly);
struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2);
struct Node *addnode(struct Node *head, int coeff, int exp);

int main()
{
    printf("Creating the first polynomial:\n");
    create(&poly);
    printf("\nCreating the second polynomial:\n");
    create(&poly1);

    printf("\nDisplaying the first polynomial:\n");
    Display(poly);

    printf("\nDisplaying the second polynomial:\n");
    Display(poly1);

    struct Node *result = multiplyPolynomials(poly, poly1);

    printf("\nMultiplication result:\n");
    Display(result);

    return 0;
}

void create(struct Node **poly2)
{
    struct Node *t, *last = NULL;
    int num, i;

    printf("Enter number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp:\n");

    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;

        if (*poly2 == NULL)
        {
            *poly2 = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *poly)
{
    struct Node *temp;
    temp = poly;

    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        else
        {
            printf("\n");
        }
        temp = temp->next;
    }
}

struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *temp1 = poly1;

    while (temp1 != NULL)
    {
        struct Node *temp2 = poly2;
        while (temp2 != NULL)
        {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            result = addnode(result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return result;
}

struct Node *addnode(struct Node *head, int coeff, int exp)
{
    struct Node *ptr;
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->coeff = coeff;
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
