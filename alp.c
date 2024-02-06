#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new linked list from every alternate element
struct Node* createAlternateList(struct Node* originalList) {
    if (originalList == NULL || originalList->next == NULL) {
        return NULL; // Nothing to do for an empty or single-node list
    }

    struct Node* newLinkedList = NULL;
    struct Node* currentOriginalNode = originalList;
    struct Node* newLinkedListHead = NULL;
    struct Node* newLinkedListTail = NULL;
    int isAlternate = 0;

    while (currentOriginalNode != NULL) {
        if (isAlternate == 0) {
            // Create a new node for the alternate list
            struct Node* newNode = createNode(currentOriginalNode->data);
            if (newLinkedList == NULL) {
                newLinkedList = newNode;
                newLinkedListHead = newLinkedList;
            } else {
                newLinkedListTail->next = newNode;
            }
            newLinkedListTail = newNode;
            isAlternate = 1;
        } else {
            isAlternate = 0;
        }
        currentOriginalNode = currentOriginalNode->next;
    }

    return newLinkedListHead;
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a sample linked list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original Linked List:\n");
    printList(head);

    struct Node* newHead = createAlternateList(head);

    printf("New Linked List with Alternate Elements:\n");
    printList(newHead);

    // Clean up memory (not shown in the pseudocode)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    while (newHead != NULL) {
        struct Node* temp = newHead;
        newHead = newHead->next;
        free(temp);
    }

    return 0;
}
