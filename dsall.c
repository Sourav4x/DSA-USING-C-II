struct node {
    int data;
    struct node *next;
} *head;

int main() {
    int n, choice, pos, ele;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    if (n > 0) {
        createList(n);
    }

    printf("\nPress 1 to traverse the linked list\n");
    printf("\nPress 2 to check if it is empty or not\n");
    printf("\nPress 3 to insert a new node at the beginning\n");
    printf("\nPress 4 to insert a new node at the end\n");
    printf("\nPress 5 to insert a new node at a given position\n");
    printf("\nPress 6 to delete a node from the beginning\n");
    printf("\nPress 7 to delete a node from the end\n");
    printf("\nPress 8 to delete a node from a given position\n");
    printf("\nPress 9 to delete a node with a given key\n");
    printf("\nPress 10 to count the total number of nodes\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            displayList();
            break;
        case 2:
            empty();
            break;
        case 3:
            insertBeg();
            displayList();
            break;
        case 4:
            insertEnd();
            displayList();
            break;
        case 5:
            insertMiddle();
            displayList();
            break;
        case 6:
            delBeg();
            displayList();
            break;
        case 7:
            delEnd();
            displayList();
            break;
        case 8:
            deleteAny();
            displayList();
            break;
        case 9:
            printf("Enter the element to be deleted: ");
            scanf("%d", &ele);
            delEle(ele);
            displayList();
            break;
        case 10:
            tNodes();
            displayList();
            break;
    }

    return 0;
}

void createList(int n) {
    struct node *newNode, *temp;
    int data;

    head = (struct node *)malloc(sizeof(struct node));
    if (n > 0) {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;

       
