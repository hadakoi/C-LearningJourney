#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
typedef struct node {
    int info;
    struct node *link;
} *NODE; // NODE is now a pointer to struct node

// Function to create a new stack node
NODE NewNode(int item) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->info = item;
    newNode->link = NULL;
    return newNode;
}

// Function to push an item onto the stack
void Push(NODE *top, int item) {
    NODE newNode = NewNode(item);
    newNode->link = *top; // Link the new node to the current top
    *top = newNode;       // Update the top to the new node
}

// Function to pop an item from the stack
int Pop(NODE *top) {
    if (*top == NULL) {
        printf("Stack is empty. No item to pop.\n");
        return -1; // Return -1 to indicate an empty stack
    }
    
    NODE temp = *top; // Store the current top node
    int poppedValue = temp->info; // Get the value to return
    *top = temp->link; // Update the top to the next node
    free(temp); // Free the old top node
    return poppedValue; // Return the popped value
}

// Function to display the stack
void DisplayStack(NODE top) {
    NODE current = top; // Start from the top of the stack
    if (current == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("%d\n", current->info);
        current = current->link; // Move to the next node
    }
}

int main() {
    NODE top = NULL; // Initialize an empty stack

    // Push items onto the stack
    Push(&top, 10);
    Push(&top, 20);
    Push(&top, 30);

    // Display the stack
    DisplayStack(top);

    // Pop an item from the stack
    printf("Popped item: %d\n", Pop(&top));
    
    // Display the stack again
    DisplayStack(top);

    // Free remaining items in the stack
    while (top != NULL) {
        Pop(&top); // Pop all items
    }

    return 0;
}
