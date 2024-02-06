/*sourav 22051031 stacks*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
int stack[max];
int top=-1;
int c=1;
char pop()
{
    char v;
    if(top==-1)
    {
        printf("\n stack underflow");
     }
    else{
        v=stack[top];
       top--;
       }
       return v;
}
void push(char chr)
{
    if(top==(max-1))
    {
        printf("\nstack overflow");
    }
    else{
        top++;
        stack[top]=chr;

    }
}
int main()
{
    int i;char asci;
    char s[max];
    printf("\nenter the elements with paranthesis:-- ");
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
      if(s[i]=='(' || s[i]=='{' || s[i]=='[')
      {
        push(s[i]);
      }
      else if(s[i]==')' || s[i]=='}' || s[i]==']')
      { 
        if(top==-1)
        {
          c=0;
        }
        else{
           asci=pop();
           if(s[i]==')' && (asci=='{' || asci=='[') )
           {
            c=0;
           }
           else if(s[i]=='}' && (asci=='(' || asci=='['))
           {
                c=0;
           }
           else if(s[i]==']' && (asci=='(' || asci=='{'))
           {
            c=0;
           }
        }

      }

    }
    if(top>=0)
    c=0;
    if(c==1)
    {
        printf("\n It's a valid expression\n");
    }
    else if(c==0)
    {
        printf("it is not valid expression\n");
    }

}