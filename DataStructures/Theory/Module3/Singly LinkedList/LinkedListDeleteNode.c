#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *link;
} *NODE; // NODE is now a pointer to struct node

NODE NewNode(int item) {
    NODE TempNode = (NODE)malloc(sizeof(struct node)); 
    TempNode->info = item; 
    TempNode->link = NULL; 
    return TempNode; 
}

void InsertAtPosition(NODE *head, int item, int position) {
    NODE newNode = NewNode(item); 
    if (position == 0) { 
        newNode->link = *head; 
        *head = newNode; 
        return;
    }

    NODE current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->link; 
    }

    if (current != NULL) {
        newNode->link = current->link; 
        current->link = newNode; 
    } else {
        free(newNode);
        printf("Position is out of bounds. Node not inserted.\n");
    }
}

void DeleteNode(NODE *head, int position) {
    if (*head == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    NODE current = *head;

    // Check if the first node (position 0) needs to be deleted
    if (position == 0) {
        *head = current->link;  // Update head to the next node
        free(current);  // Free the old head
        return;
    }

    // Traverse to the node just before the one to be deleted
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->link;
    }

    // If the position is beyond the length of the list or the next node is NULL
    if (current == NULL || current->link == NULL) {
        printf("Position is out of bounds. No node deleted.\n");
        return;
    }

    NODE temp = current->link;  // Node to be deleted

    // Check if this is the last node
    if (temp->link == NULL) {
        current->link = NULL;  // Update link to NULL, effectively deleting the last node
    } else {
        current->link = temp->link;  // Skip the node to delete
    }

    free(temp);  // Free the node
}

void DisplayNode(NODE head) {
    NODE current = head; // Start from the head
    while (current != NULL) { // Traverse until the end of the list
        printf("%d\n", current->info); // Print the info
        current = current->link; // Move to the next node
    }
}

int main() {
    NODE head = NULL; // Initialize an empty list

    // Insert nodes at various positions
    InsertAtPosition(&head, 1, 0); // Insert 1 at position 0
    InsertAtPosition(&head, 2, 1); // Insert 2 at position 1
    InsertAtPosition(&head, 3, 1); // Insert 3 at position 1 (in between 1 and 2)

    printf("Linked List before deletion:\n");
    DisplayNode(head); // Display the linked list

    // Delete nodes
    DeleteNode(&head, 1); // Delete the node at position 1

    printf("Linked List after deleting node at position 1:\n");
    DisplayNode(head); // Display the linked list again

    // Free allocated memory
    NODE current = head;
    while (current != NULL) {
        NODE next = current->link; // Store the next node
        free(current); // Free current node
        current = next; // Move to the next node
    }

    return 0;
}

