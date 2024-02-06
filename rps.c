#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
char st[MAX];
int top = -1;

char pop(char st[]);
void push(char st[], char c);
void infixtoprefix(char source[], char target[]);
int getpriority(char);
void reversestring(char str[]);

void main()
{
    char infix[100], prefix[100];

    int i, c = 0, j;

    printf("\n Enter any infix expression: ");
    gets(infix);
    strcpy(prefix, "");

    infixtoprefix(infix, prefix);

    printf("\n The corresponding prefix expression is: %s", prefix);
}

void reversestring(char str[])
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

void infixtoprefix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");

    reversestring(source); // Reverse the infix expression first

    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == ')')
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

            temp = pop(st); // Remove left parenthesis
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
                 source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (st[top] != '(') &&
                   (getpriority(st[top]) >= getpriority(source[i])))
            {
                target[j] = pop(st);
                j++;
            }

            push(st, source[i]);
            i++;
        }
        else
        {
            printf("\n INCORRECT ELEMENT IN THE EXPRESSION");
            exit(1);
        }
    }

    while ((top != -1) && (st[top] != '('))
    {
        target[j] = pop(st);
        j++;
    }

    target[j] = '\0';

    reversestring(target); // Reverse the result to get the prefix expression
}

int getpriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;

    return -1; // Handle other cases (not operators)
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
