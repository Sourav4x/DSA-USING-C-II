#include<stdio.h>
#include<string.h>

#define MAX 100
int stk[MAX];
int top=-1;

char pop();
void push(char);

void main()
{
 char ch[MAX];
 int i;

        printf("\n Enter an expression");
        gets(ch);


  for(i=0;i<strlen(s);i++)
   {

    if(ch[i]=='*')
    {
       
        
        printf("%c",pop());
    }
    else
    {
        push(ch[i]);
    }
   }
}

void push(char c)
{
  if(top==(MAX-1))
   printf("\nStack overflow");

   else
   {
    top++;
    stk[top]=c;
   }
}

char pop()
{
  char c;
  if(top==-1)
   printf("\nStack underflow");
  
  else
  c=stk[top];
    top--; 
  return c;
}