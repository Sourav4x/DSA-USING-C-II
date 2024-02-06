#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct Node
{
 int coeff;
 int exp;
 struct Node *next;
}*poly=NULL,*poly1=NULL;
 void create(struct Node **poly2)
{
 struct Node *t,*last=NULL;
 int num,i;
 
 printf("Enter number of terms");
 scanf("%d",&num);
 printf("Enter each term with coeff and exp\n");
 
 for(i=0;i<num;i++)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 scanf("%d%d",&t->coeff,&t->exp);
 t->next=NULL;
 if(*poly2==NULL)
 {
 *poly2=last=t;
 }
 else
 {
 last->next=t;
 last=t;
 }
 }
}
void Display(struct Node *poly)
{
    struct Node *temp;
    temp=poly;
 while(temp!=NULL)
 {
 printf("%dx^%d",temp->coeff,temp->exp);
 if(temp->next!=NULL)
 {
    printf("+");
 }
 else{
 
 printf("\n");
}
temp=temp->next;
 }
}

int main()
{
    printf("creating first polynomail:-  ");
 create(&poly);
 printf("\n creating 2nd polynomial:-- ");
 create(&poly1);
 printf("\ndisplaying the 1st polynomial:-");
 Display(poly);
 printf("\n");
 printf("\n displaying the 2nd polynomial:-  ");
 Display(poly1);
 return 0;
}