#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term node
struct Term* createTerm(int coeff, int exp) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->coefficient = coeff;
    term->exponent = exp;
    term->next = NULL;
    return term;
}

// Function to add a new term to the polynomial
void addTerm(struct Term** poly, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    while (poly != NULL) {
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
}

int main() {
    struct Term* polynomial = NULL;
    int coeff, exp;
    char addAnother;

    do {
        // Input coefficient and exponent from the user
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &exp);

        // Add the term to the polynomial
        addTerm(&polynomial, coeff, exp);

        // Ask if the user wants to add another term
        printf("Add another term? (y/n): ");
        scanf(" %c", &addAnother);

    } while (addAnother == 'y' || addAnother == 'Y');

    // Display the polynomial
    printf("Polynomial: ");
    displayPolynomial(polynomial);

    // Free memory
    while (polynomial != NULL) {
        struct Term* temp = polynomial;
        polynomial = polynomial->next;
        free(temp);
    }

    return 0;
}