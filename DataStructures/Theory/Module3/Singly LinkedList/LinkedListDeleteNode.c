#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct node {
    int info;
    struct node *link;
} *NODE;

// Function to create a new node
NODE NewNode(int item) {
    NODE TempNode = (NODE)malloc(sizeof(struct node));
    TempNode->info = item;
    TempNode->link = NULL;
    return TempNode;
}

// Function to insert a node at the end of the list
void insertEnd(NODE *head, int item) {
    NODE newNode = NewNode(item);
    if (*head == NULL) {
        *head = newNode;
    } else {
        NODE temp = *head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

// Function to delete the head node from the linked list
void deleteHead(NODE *head) {
    if (*head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    NODE current = *head; // Store the current head
    *head = current->link; // Update head to the next node
    free(current); // Free the old head
}

// Function to delete a node from the rear of the linked list
void deleteRear(NODE *head) {
    if (*head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    NODE current = *head;

    // If there's only one node
    if (current->link == NULL) {
        free(current); // Free the node
        *head = NULL;  // Update head to NULL
        return;
    }

    // Traverse to the second last node
    while (current->link->link != NULL) {
        current = current->link;
    }

    // Free the last node
    free(current->link);
    current->link = NULL; // Set the second last node's link to NULL
}

// Function to delete a node at a specific position
void deleteAtPosition(NODE *head, int position) {
    if (*head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    NODE current = *head;

    // If the head node is to be deleted
    if (position == 0) {
        *head = current->link; // Update head to the next node
        free(current); // Free the old head
        return;
    }

    // Traverse to the node before the desired position
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->link;
    }

    // If the previous node is NULL or if the position is out of bounds
    if (current == NULL || current->link == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    NODE nodeToDelete = current->link; // Node to be deleted
    current->link = nodeToDelete->link; // Bypass the node
    free(nodeToDelete); // Free the deleted node
}

// Function to display the linked list
void DisplayList(NODE head) {
    NODE temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

// Main function to demonstrate deletion from head, rear, and at position
int main() {
    NODE head = NULL;

    // Insert nodes into the linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    
    printf("Original Linked List: ");
    DisplayList(head); // Display original list

    // Delete the head node
    deleteHead(&head);
    printf("Linked List after deleting the head node: ");
    DisplayList(head); // Display the list after head deletion

    // Delete the rear node
    deleteRear(&head);
    printf("Linked List after deleting the rear node: ");
    DisplayList(head); // Display the list after rear deletion

    // Delete a node at position 1
    deleteAtPosition(&head, 1);
    printf("Linked List after deleting the node at position 1: ");
    DisplayList(head); // Display the list after position deletion

    return 0;
}
