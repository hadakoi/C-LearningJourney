#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *link;
} *NODE; // NODE is now a pointer to struct node

NODE NewNode(int item) {
    NODE TempNode = (NODE)malloc(sizeof(struct node)); // Allocate memory for a struct node
    TempNode->info = item; // Assign value to info
    TempNode->link = NULL; // Initialize link to NULL
    return TempNode; // Return pointer to the new node
}

void InsertAtBeginning(NODE *head, int item) {
    NODE newNode = NewNode(item);
    newNode->link = *head; 
    *head = newNode; 
}

void DisplayNode(NODE head) {
    NODE current = head;
    while (current != NULL) {
        printf("%d\n", current->info);
        current = current->link;
    }
}

int main() {
    NODE head = NULL; 

    InsertAtBeginning(&head, 3);
    InsertAtBeginning(&head, 2);
    InsertAtBeginning(&head, 1); 

    printf("Linked List after insertions at beginning:\n");
    DisplayNode(head); 


    NODE current = head;
    while (current != NULL) {
        NODE next = current->link;
        free(current);
        current = next;
    }

    return 0;
}
