#include<stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int deg;
    struct node *next;
}*term;


 int create(int coeff, int exp) 
{
    term= (struct node*)malloc(sizeof(struct node));
    term->coef = coeff;
    term->deg= exp;
    term->next = NULL;
    return term;

}

void addTerm(struct node *poly,int coeff, int exp) 
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


int main()
{
    struct node *poly;
    poly!=NULL;
    int coeff;
    int exp,newpoly;
    printf("\n Enter coef of the polynomial\n");
    scanf("%d",&coeff);
    printf("enter the degree of the polynomial\n");
    scanf("%d",&exp);
    addTerm(&poly,coeff,exp)
    printf("\nenter 1 to add more polynomials and enter 2 to stop\n");
    scanf("%d",&newpoly);
}while(newpoly==1);
 printf("Polynomial: ");
    displayPolynomial(polynomial);
