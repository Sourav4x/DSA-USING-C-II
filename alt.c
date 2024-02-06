#include <stdio.h>
#include <stdlib.h>

Node *head;

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *create_alternate_linked_list()
 {

  Node *new_head = NULL;
  Node *new_tail = NULL;
  Node *current_node = head;
  while (current_node != NULL) {
    Node *next_node = current_node->next;
    if (current_node->data != NULL) {
      Node *new_node = malloc(sizeof(Node));
      new_node->data = current_node->data;
      new_node->next = NULL;
      if (new_head == NULL) {
        new_head = new_node;
        new_tail = new_node;
      } else {
        new_tail->next = new_node;
        new_tail = new_node;
      }
    }

    current_node = next_node;
  }

  return new_head;
}

void print_linked_list(Node *head) {

  Node *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

int main() {
  head = malloc(sizeof(Node));
  head->data = 1;
  head->next = malloc(sizeof(Node));
  head->next->data = 2;
  head->next->next = malloc(sizeof(Node));
  head->next->next->data = 3;
  head->next->next->next = malloc(sizeof(Node));
  head->next->next->next->data = 4;
  head->next->next->next->next = NULL;

  printf("Original linked list: ");
  print_linked_list(head);

  Node *new_head = create_alternate_linked_list();

  printf("New linked list with every alternate element: ");
  print_linked_list(new_head);

  return 0;
}
