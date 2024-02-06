#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
char st[MAX];
int top = -1;

char pop(char st[]);
void push(char st[], char c);
void infixtoprefix(char src[], char target[]);
int getpriority(char);
void revstr(char str[]);

void main()
{
    char infix[100], prefix[100];

    int i, c = 0, j;

    printf("enter any infix expression:--- ");
    gets(infix);
    strcpy(prefix, "");

    infixtoprefix(infix, prefix);

    printf("\n The corresponding prefix expression is: %s", prefix);
}

void revstr(char str[])
{
    char v;
    int l = strlen(str);
    for (int i = 0, j = l - 1; i < j; i++, j--)
    {
        v = str[i];
        str[i] = str[j];
        str[j] = v;
    }
}

void infixtoprefix(char src[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");

    revstr(src); 

    while (src[i] != '\0')
    {
        if (src[i] == '(')
        {
            src[i] = ')';
            i++;
        }
        else if (src[i] == ')')
        {
            src[i] = '(';
            i++;
        }
        i++;
    }

    i = 0;

    while (src[i] != '\0')
    {
        if (src[i] == '(')
        {
            push(st, src[i]);
            i++;
        }
        else if (src[i] == ')')
        {
            while ((top != -1) && (st[top] != '('))
            {
                target[j] = pop(st);
                j++;
            }

            if (top == -1 || st[top] != '(')
            {
                printf("\n INCORRECT EXPRESSION");
                exit(1);
            }

            temp = pop(st); 
            i++;
        }
        else if (isdigit(src[i]) || isalpha(src[i]))
        {
            while (isdigit(src[i]) || isalpha(src[i]))
            {
                target[j] = src[i];
                j++;
                i++;
            }
            target[j] = ' ';
            j++;
        }
        else if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' || src[i] == '%')
        {
            while ((top != -1) && (st[top] != '(') && (getpriority(st[top]) >= getpriority(src[i])))
            {
                target[j] = pop(st);
                j++;
            }

            push(st, src[i]);
            i++;
        }
        else
        {
            printf("\n incorrect expression");
            exit(1);
        }
    }

    while ((top != -1) && (st[top] != '('))
    {
        target[j] = pop(st);
        j++;
    }

    target[j] = '\0';

    revstr(target);
}

int getpriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;

    return -1; 
}

void push(char st[], char val)
{
    if (top == (MAX - 1))
        printf("\nStack overflow");
    else
    {
        top++;
        st[top] = val;
    }
}

char pop(char st[])
{
    char val = ' ';
    if (top == -1)
        printf("\nStack underflow");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}
