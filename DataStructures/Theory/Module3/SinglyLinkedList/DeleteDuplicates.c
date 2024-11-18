#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} *NODE;

// Function to create a new node
NODE create_node(int data) {
    NODE new_node = (NODE)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the list
void insert(NODE* head, int data) {
    NODE new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to delete duplicates in a sorted singly linked list
void delete_duplicates(NODE head) {
    NODE current = head;
    NODE prev = NULL;
    
    // Traverse the list
    while (current != NULL && current->next != NULL) {
        prev = current;
        
        // If the current node's data is equal to the next node's data, delete the next node
        if (current->data == current->next->data) {
            NODE temp = current->next;
            current->next = current->next->next; // Bypass the duplicate node
            free(temp); // Free the duplicate node
        } else {
            current = current->next; // Move to the next node
        }
    }
}

// Function to print the list
void print_list(NODE head) {
    NODE current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    NODE head = NULL;

    // Insert elements into the linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 3);
    insert(&head, 3);
    insert(&head, 4);
    
    printf("Original list:\n");
    print_list(head);

    // Remove duplicates
    delete_duplicates(head);

    printf("List after removing duplicates:\n");
    print_list(head);

    return 0;
}
