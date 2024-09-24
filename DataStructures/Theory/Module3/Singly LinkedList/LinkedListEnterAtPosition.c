#include <stdio.h>
#include <stdlib.h>

// Node structure with link as a pointer to the next Node
typedef struct Node {
    int data;
    struct Node* link; // Pointer to the next node
} *NODE;

// Function to create a new node
NODE createNode(int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to insert a node at the front
void insertAtFront(NODE* head, int data) {
    NODE newNode = createNode(data);
    newNode->link = *head;
    *head = newNode;
}

// Function to insert a node at the rear
void insertAtRear(NODE* head, int data) {
    NODE newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    NODE current = *head;
    while (current->link != NULL) {
        current = current->link;
    }
    current->link = newNode;
}

// Function to insert a node at a specific position (1-based index)
void insertAtPosition(NODE* head, int data, int position) {
    NODE newNode = createNode(data);

    if (position == 1) {
        newNode->link = *head;
        *head = newNode;
        return;
    }

    NODE current = *head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->link;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->link = current->link;
    current->link = newNode;
}

// Function to print the linked list
void printList(NODE head) {
    NODE current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->link;
    }
    printf("NULL\n");
}

int main() {
    NODE head = NULL;

    insertAtFront(&head, 3);
    insertAtRear(&head, 5);
    insertAtFront(&head, 1);
    insertAtPosition(&head, 4, 2);
    insertAtPosition(&head, 2, 2);
    insertAtPosition(&head, 6, 10);  // Position out of bounds

    printList(head);

    return 0;
}