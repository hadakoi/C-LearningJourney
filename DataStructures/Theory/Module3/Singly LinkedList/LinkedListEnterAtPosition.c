#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the linked list
typedef struct node {
    int info;
    struct node *link;
} *NODE;

// Function to create a new node with a given value
NODE NewNode(int item) {
    NODE TempNode = (NODE)malloc(sizeof(struct node));
    TempNode->info = item;
    TempNode->link = NULL;
    return TempNode;
}

// Function to insert a node at a specified position or at the rear
void InsertAtPosition(NODE *head, int item, int position) {
    NODE newNode = NewNode(item);

    if (position == 0 || *head == NULL) { // Insert at the front or in an empty list
        newNode->link = *head;
        *head = newNode;
        return;
    }

    NODE current = *head;
    int i;

    // Traverse to the node just before the desired position
    for (i = 0; i < position - 1 && current->link != NULL; i++) {
        current = current->link;
    }

    // If the position is within bounds, or we've reached the end, insert the new node
    newNode->link = current->link;
    current->link = newNode;
}

// Function to display the contents of the linked list
void DisplayNode(NODE head) {
    NODE current = head;
    while (current != NULL) {
        printf("%d\n", current->info);
        current = current->link;
    }
}

// Main function to demonstrate the InsertAtPosition function
int main() {
    NODE head = NULL;

    InsertAtPosition(&head, 1, 0); // Insert 1 at position 0
    InsertAtPosition(&head, 2, 1); // Insert 2 at position 1
    InsertAtPosition(&head, 3, 5); // Attempt to insert 3 at position 5 (inserts at rear)
    InsertAtPosition(&head, 4, 2); // Insert 4 at position 2

    printf("Linked List after insertions:\n");
    DisplayNode(head);

    // Free allocated memory
    NODE current = head;
    while (current != NULL) {
        NODE next = current->link;
        free(current);
        current = next;
    }

    return 0;
}
