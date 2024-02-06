#include <stdio.h>
#include <stdlib.h>
struct node {
    int coefficient;
    int exponent;
    struct node* next;
};

struct node* createTerm(int coef, int exp) 
{
    struct node* newTerm = (struct node*)malloc(sizeof(struct node));
    if (newTerm == NULL)
     {
        printf("Memory allocation failed.");
    
    }
    else
    {
    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    return newTerm;
}
}
void addTerm(struct node** poly, int coef, int exp)
 {
    struct node* newTerm = createTerm(coef, exp);
    if (*poly == NULL)
     {
        *poly = newTerm;
    } else
     {
        struct node* current = *poly;
        while (current->next != NULL)
         {
            current = current->next;
        }
        current->next = newTerm;
    }
}
void displayPolynomial(struct node* poly)
 {
    if (poly == NULL)
     {
        printf("Polynomial is empty.\n");
        return;
    }

    printf("Polynomial: ");
    while (poly != NULL) {
        if (poly->coefficient != 0) 
        {
            if (poly->exponent == 0) 
            {
                printf("%d", poly->coefficient);
            } else {
                printf("%dx^%d", poly->coefficient, poly->exponent);
            }
            if (poly->next != NULL && poly->next->coefficient != 0) {
                printf(" + ");
            }
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct node* polynomial = NULL;
    int n, coef, exp;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coef, &exp);
        addTerm(&polynomial, coef, exp);
    }

    displayPolynomial(polynomial);
    struct node* current = polynomial;
    while (current != NULL) 
    {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
