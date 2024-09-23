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

void DisplayNode(NODE head) {
    NODE current = head;
    while (current != NULL) {
        printf("%d\n", current->info);
        current = current->link;
    }
}

int main() {
    NODE head, second, last;

    head = NewNode(1);
    second = NewNode(2);
    last = NewNode(3);

    head->link = second; // Link first node to second
    second->link = last; // Link second node to last

    printf("Linked List:\n");
    DisplayNode(head); // Display the linked list

    // Free allocated memory
    free(last);
    free(second);
    free(head);

    return 0;
}
