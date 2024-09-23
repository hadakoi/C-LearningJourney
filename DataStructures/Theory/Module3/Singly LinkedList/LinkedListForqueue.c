#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
typedef struct node {
    int info;
    struct node *link;
} *NODE;

NODE NewNode(int item) {
    NODE newNode = (NODE)malloc(sizeof(struct node));
    newNode->info = item;
    newNode->link = NULL;
    return newNode;
}

// Function to enqueue an item to the queue
void Enqueue(NODE *front, NODE *rear, int item) {
    NODE newNode = NewNode(item);
    if (*rear == NULL) {
        // If the queue is empty, both front and rear point to the new node
        *front = *rear = newNode;
        return;
    }
    // Link the new node at the end of the queue and update the rear
    (*rear)->link = newNode;
    *rear = newNode;
}

// Function to dequeue an item from the queue
int Dequeue(NODE *front) {
    if (*front == NULL) {
        printf("Queue is empty. No item to dequeue.\n");
        return -1; // Return -1 to indicate an empty queue
    }
    
    NODE temp = *front; // Store the current front node
    int dequeuedValue = temp->info; // Get the value to return
    *front = temp->link; // Update the front to the next node
    free(temp); // Free the old front node
    return dequeuedValue; // Return the dequeued value
}

// Function to display the queue
void DisplayQueue(NODE front) {
    NODE current = front; // Start from the front of the queue
    if (current == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue contents:\n");
    while (current != NULL) {
        printf("%d\n", current->info);
        current = current->link; // Move to the next node
    }
}

int main() {
    NODE front = NULL; // Initialize the front of the queue
    NODE rear = NULL;  // Initialize the rear of the queue

    // Enqueue items to the queue
    Enqueue(&front, &rear, 10);
    Enqueue(&front, &rear, 20);
    Enqueue(&front, &rear, 30);

    // Display the queue
    DisplayQueue(front);

    // Dequeue an item from the queue
    printf("Dequeued item: %d\n", Dequeue(&front));
    
    // Display the queue again
    DisplayQueue(front);

    // Free remaining items in the queue
    while (front != NULL) {
        Dequeue(&front); // Dequeue all items
    }

    return 0;
}
