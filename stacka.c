/*22051031 sourav stack prog*/
#include<stdio.h>
#define num 10
int sk[num];
int top=-1;
void push(int s[],int v)
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
   top--;
   return(sk[top+1]);
  }
}
int peek(int a[])
{
 return a[top];
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
    for(i=top;i>=0;i--)
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
        printf("\n 4)Peek operation");
        printf("\n 5) exit");
        printf("\n Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:printf("displaying the stack:-- ");
            display(sk);
            break;

           case 2: printf("\n Enter the number to be pushed in stack :");
               scanf("%d",&val);
               push(sk,val);
               break;

            case 3: val=pop(sk);
               if(val!=-1)
               {
                printf("\nthe number deleted in the stack is %d",val);
               }
               printf("\ndisplaying the stack now");
               display(sk);
               break;
            case 4:val=peek(sk);
               if(val!=-1)
               {
                printf("the value stored in the top of our stack is :-- %d",val);
               }
               break;
            case 5: 
              return -1;
        }

        }while(choice!=6);

       

}
