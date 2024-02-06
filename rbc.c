#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

#define MAX_LEN 100

// Function to check if a character is an opening or closing bracket
bool isBracket(char ch) {
    return (ch == '(' || ch == ')');
}

// Function to remove redundant brackets
void removeRedundantBrackets(char expression[]) {
    int len = strlen(expression);
    int top = -1; // Initialize the stack for tracking opening brackets

    for (int i = 0; i < len; i++) {
        if (isBracket(expression[i])) {
            if (expression[i] == '(') {
                // Push the index of the opening bracket onto the stack
                top++;
                expression[top] = i;
            } else if (expression[i] == ')' && top >= 0) {
                // Mark the current closing bracket and its matching opening bracket as non-redundant
                expression[i] = ' ';
                expression[expression[top]] = ' ';
                top--; // Pop the matching opening bracket from the stack
            }
        }
    }
}

int main() {
    char expression[MAX_LEN];

    printf("Enter an expression with potentially redundant brackets: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove redundant brackets
    removeRedundantBrackets(expression);

    // Print the expression with redundant brackets removed
    printf("Expression with redundant brackets removed: %s\n", expression);

    return 0;
}
