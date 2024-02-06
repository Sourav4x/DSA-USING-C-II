#include <stdio.h>
#include <stdlib.h>
struct node {
    int coefficient;
    int exponent;
    struct node* next;
};

struct node* createTerm(int coeff, int exp) 
{
    struct node* term ;
    term= (struct node*)malloc(sizeof(struct node));
    term->coefficient = coeff;
    term->exponent = exp;
    term->next = NULL;
    return term;
}
void addTerm(struct node** poly, int coeff, int exp) 
{
    struct node* newTerm = createTerm(coeff, exp);
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
void displayPolynomial(struct Term* polynomial)
 {
    if (polynomial == NULL) {
        printf("Polynomial is empty.\n");

    }

}
    while(polynomial != NULL) {
        if (poly->coefficient != 0) {
            printf("%dx^%d", poly->coefficient, poly->exponent);
            if (poly->next != NULL && poly->next->coefficient > 0) {
                printf(" + ");
            } else if (poly->next != NULL && poly->next->coefficient < 0) {
                printf(" - ");
            }
        }
        poly = poly->next;
    }
    printf("\n");

int main() {
    struct node* polynomial = NULL;
    int coeff, exp;
    int addAnother;

    do {
    
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &exp);

    
        addTerm(&polynomial, coeff, exp);

        
        printf("Add another term(1 to yes and 2 to no): ");
        scanf(" %d", &addAnother);

    } while (addAnother ==1);


    printf("Polynomial: ");
    displayPolynomial(polynomial);


    while (polynomial != NULL) {
        struct node* temp = polynomial;
        polynomial = polynomial->next;
        free(temp);
    }

    return 0;
}