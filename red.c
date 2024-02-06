#include <stdio.h>
#include <string.h>

#define MAX_EXPR_LENGTH 100

int stack[MAX_EXPR_LENGTH];
int top = -1;

// Function to push an element onto the stack
void push(int val) {
    stack[++top] = val;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        return -1; // Stack underflow
    }
    return stack[top--];
}

int main() {
    char expression[MAX_EXPR_LENGTH];
    printf("Enter an expression with redundant brackets: ");
    fgets(expression, sizeof(expression), stdin);
    
    int len = strlen(expression);

    for (int i = 0; i < len; i++) {
        if (expression[i] == '(') {
            push(i);
        } else if (expression[i] == ')') {
            int topIndex = pop();
            if (topIndex != -1) {
                // Mark both the current ')' and the popped '(' as not redundant
                expression[i] = ' ';
                expression[topIndex] = ' ';
            } else {
                // Mark the current ')' as redundant
                expression[i] = '-';
            }
        }
    }

    // Remove redundant brackets and print the result
    printf("Expression with redundant brackets removed: ");
    for (int i = 0; i < len; i++) {
        if (expression[i] != '-' && expression[i] != ' ') {
            putchar(expression[i]);
        }
    }

    return 0;
}
