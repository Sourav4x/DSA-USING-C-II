#include <stdio.h>//infix to postfix
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char stack[100];
int top = -1;

void infixToPostfix(char[], char[]);
int priority(char);
void push(char);
char pop();
void display();

int main()
{
    char infix[100], postfix[100];
    printf("ENTER THE INFIX EXPRESSION\n");
    gets(infix);
    strcpy(postfix, "");
    infixToPostfix(infix, postfix);
    return 0;
}

void infixToPostfix(char s[], char e[])
{
    int i = 0, j = 0;
    char temp;
    while (s[i] != '\0')
    {
        if (s[i] == '(')
        {
            push(s[i]);
            i++;
        }
        else if (s[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                e[j] = pop();
                j++;
            }
            if (top == -1)
            {
                printf("INVALID EXPRESSION\n");
                exit(1); 
            }
            temp = pop();
            i++;
        }
        else if (isdigit(s[i]) || isalpha(s[i]))
        {
            e[j] = s[i];
            j++;
            i++;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '^' || s[i] == '*' || s[i] == '/' || s[i] == '%')
        {
            while (top != -1 && stack[top] != '(' && priority(stack[top]) >= priority(s[i]))
            {
                e[j] = pop();
                j++;
            }
            push(s[i]);
            i++;
        }
        else
        {
            printf("INVALID EXPRESSION\n");
            exit(1); // exit function needs an argument
        }
    }
    while (top != -1)
    {
        e[j] = pop();
        j++;
    }
    e[j] = '\0';
    printf("The postfix expression is\n");
    puts(e);
}

int priority(char op)
{
    if (op == '^')
    {
        return 2;
    }
    else if (op == '/' || op == '*' || op == '%')
    {
        return 1;
    }
    else if (op == '+' || op == '-')
    {
        return 0;
    }
    return -1; 
}

void push(char a)
{
    if (top == 99)
    {
        printf("\n\tSTACK is over flow");
    }
    else
    {
        top++;
        stack[top] = a;
    }
}

char pop()
{
    char s;
    if (top == -1)
    {
        printf("underflow\n");
    }
    else
    {
        s = stack[top];
        top--;
    }
    return s;
}