#include<stdio.h>
struct node{
    int data;
    struct node *next
};
int traverse(struct node *ptr)
{
    while(ptr!='NULL')
    {
        printf("Element = %d\t",ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
void reverseList()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head

        printf("SUCCESSFULLY

/*void reverse()
{
    struct node *pnode,*cnode,*nextnode;
    if(head!='NULL')
    cnode=nextnode=pnode;
    while(nextnode!='NULL')
    {
        nextnode=nextnode->next;
        cnode->next=pnode;
        pnode=cnode;
        cnode=nextnode;
    }
}

void main()
{
struct node *head;
struct node *first;
struct node *second;
struct node *third;
head=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
third=(struct node*)malloc(sizeof(struct node));
head->data=8;
head->next=second;
second->data=9;
second->next=third;
third->data=4;
third->next='NULL';
reverse(head);
traverse(head);
}