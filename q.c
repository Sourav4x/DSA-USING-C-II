/*22051031 Sourav H/W*/
#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int f;
    int r;
    int size;
    int *q;
};
void create(struct queue *s,int n)
{
    s->size=n;
    s->f=s->r=-1;
    s->q=(int*)malloc(n*sizeof(int));
};
void enqueue(struct queue *s,int n)
{
    if(s->r==(s->size-1))
    {
        printf("\nMy queue is full");
    }
    else 
    {
        s->r++;
        s->q[s->r]=n;
    }
}
int dequeue(struct queue *s)
{
    int x;
    if(s->f==s->r)
    {
        printf("\nthe queue is empty");
    }
    else 
    {
      s->f++;
      x=s->q[s->f];
    }
    return x;
}
void display(struct queue *s)
{
    int i;
    for(i=s->f+1;i<=s->r;i++)
    {
        printf("%d\t",s->q[i]);
    }
}

void main()
{
    struct queue s;
     int x;
    int choice;
    do{

    printf("\nClick 1 to Create a Queue\n");
    printf("Click 2 to perform enqueue operation:-- \n");
    printf("\n Click 3 to perform dequeue operation");
    printf("\nClick 4 to display The queue\n");
    printf("\n Click 5 to exit\n");
    printf("\n Enter your choice :-- ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
        printf("\n Enter the size of ur queue:-- \n");
        scanf("%d",&x);
        create(&s,x);
        break;
        case 2:
        printf("\n Enter the value to be inserted :-- ");
        scanf("%d",&x);
        enqueue(&s,x);
        break;
        case 3:
        x= dequeue(&s);
        printf("\n The value deleted is %d\n",x);
        break;
        case 4:
        display(&s);
        break;
        case 5:
        exit(1);
        break;
    }

    
    }while(choice!=6);




}