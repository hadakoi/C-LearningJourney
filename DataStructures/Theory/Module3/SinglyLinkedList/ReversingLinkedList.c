#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int value;
    struct node *link;
} *NODE;

// Function to create a new node
NODE createNode(int value) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->link = NULL;
    return newNode;
}

// Function to insert a node at the head of the list
void insertHead(NODE *head, int value) {
    NODE newNode = createNode(value);
    newNode->link = *head;
    *head = newNode;
}

// Function to display the list
void displayList(NODE head) {
    NODE temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->link;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverseList(NODE *head) {
    NODE prev = NULL;
    NODE current = *head;
    NODE next = NULL;

    // Traverse the list and reverse the link of each node
    while (current != NULL) {
        next = current->link; // Store the next node
        current->link = prev; // Reverse the link
        prev = current;       // Move prev to the current node
        current = next;       // Move to the next node
    }

    *head = prev; // Update the head pointer to the new head (last node)
}

int main() {
    NODE head = NULL;

    // Insert elements at the head
    insertHead(&head, 10);
    insertHead(&head, 20);
    insertHead(&head, 30);

    printf("Original List: ");
    displayList(head);

    // Reverse the list
    reverseList(&head);

    printf("Reversed List: ");
    displayList(head);

    return 0;
}
