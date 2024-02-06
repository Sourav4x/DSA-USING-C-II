#include <stdio.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

int emp() {
    return top == -1;
}
void push(int data) {
    if(top==(MAX_SIZE-1))
    {
        printf("stack overflow");
    }
    {
        top++;
        stack[top]=data;
    }
}

int pop()
 {
    if (top==-1)
    {
        printf("stack underflow");
    }
    else
     {
         top--;
   return(stack[top+1]);
    }
}
void insert(int data)
 {
    if (emp() || data >= stack[top]) 
    {
        push(data);
    } else 
    {
        int temp = pop();
        insert(data);
        push(temp);
    }
}
void sortStack()
 {
    if (!emp()) 
    {
        int data = pop();
        sortStack();
        insert(data);
    }
}
void printStack() {
    for (int i = 0; i <= top; i++)
     {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int num;
    int x;

    printf("Enter the number of elements to push onto the stack:---  ");
    scanf("%d", &num);

    printf("Enter %d elements: ", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &x);
        push(x);
    }

    printf("Original Stack: ");
    printStack();

    sortStack();

    printf("Sorted Stack: ");
    printStack();

    return 0;
}
