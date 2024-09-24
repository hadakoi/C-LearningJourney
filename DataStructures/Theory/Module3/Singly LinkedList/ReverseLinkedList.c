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

// Function to reverse the linked list
void reverseList(NODE *head) {
    NODE prev = NULL;
    NODE current = *head;
    NODE next = NULL;

    while (current != NULL) {
        next = current->link;  // Store next node
        current->link = prev;  // Reverse current node's pointer
        prev = current;        // Move prev to current node
        current = next;        // Move to the next node
    }
    *head = prev;  // Update head to the new first node
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

// Main function to demonstrate the reversal
int main() {
    NODE head = NULL;

    // Insert nodes into the linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    
    printf("Original Linked List: ");
    DisplayList(head); // Display original list

    reverseList(&head); // Reverse the linked list

    printf("Reversed Linked List: ");
    DisplayList(head); // Display reversed list

    return 0;
}
