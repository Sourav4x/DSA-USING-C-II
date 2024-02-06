#include<stdio.h>
#include<stdlib.h>
#define num 10
int sk[num];
int qk[num];
int top=-1;
int top2=-1;
int c=0;
void push(int v)
{
    if(top==(num-1))
    {
       printf("\nstack overflow");
    }
    else{
        top++;
        sk[top]=v;
    }
}
int pop(int a[])
{
    if(top==-1)
  {
   printf("\nStack underflow");
   return -1;
  }  

  else
  {
    int q=sk[top];
    top--;
    return q;
  }
}
void pushagain(int y)
{
    if(top2==num-1)
    {
        printf("\nstack underflow ");
    }
    else{
        top2++;
        qk[top2]=y;

}
}
int popagain()
{
    int b=qk[top2];
    top2--;
    return b;
}
void enqueue(int a)
{
    push(a);
    c++;

}
void dequeue()  
{  
   if((top==-1) && (top2==-1))  
{  
   printf("\nour Queue empty");  
}  
else  
{  
  for(int i=0;i<c;i++)  
  {  
     int element =pop(sk);  
     pushagain(element);  
  }  
int b=popagain();  
printf("\nThe dequeued element is %d\n", b);  
c--;  
for(int i=0;i<c;i++)  
{  
   int a = popagain();  
   push(a);   
}  
}
}
void display(int s[])

{
    int i;
    if(top==-1)
    {
     printf("\nStack is empty");
    }  

  else
  {
    for(i=0;i<=top;i++)
      printf("\n%d",s[i]);
  }
}



int main()
{
  int choice,val;
  do{
        printf("\nMAIN MENU");
        printf("\n1)Display the prog");
        printf("\n 2)To push an element in Our Stack");
        printf("\n 3)Pop Operation");
        printf("\n 4) exit");
        printf("\n Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("displaying the stack:-- ");
            display(sk);
            break;

           case 2: printf("\n Enter the number to be pushed in stack :");
               scanf("%d",&val);
               enqueue(val);
               break;

            case 3: dequeue();
               printf("\ndisplaying the stack now");
               display(sk);
               break;
            case 4:exit(1);
        }

        }while(choice!=5);

     return 0;  

}
