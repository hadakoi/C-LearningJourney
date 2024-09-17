#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
  int x[MAX];    // Array to store queue elements
  int front;     // Index of the front element in the queue
  int rear;      // Index of the rear element in the queue
} queue;

// Function to initialize the queue
void initializeQueue(queue *q) {
  q->front = 0;  // Initialize front to 0
  q->rear = 0;   // Initialize rear to 0
}

// Function to check if the queue is full
int isQueueFull(queue *q) {
  // The queue is full if rear has reached MAX
  return q->rear == MAX;
}

// Function to check if the queue is empty
int isQueueEmpty(queue *q) {
  // The queue is empty if front and rear are the same
  return q->front == q->rear;
}

// Function to insert an element into the queue
void insertq(queue *q, int x) {
  // Check if the queue is full
  if (isQueueFull(q)) {
    printf("\nOverflow\n");  // Queue is full, cannot insert
  } else {
    q->x[q->rear++] = x;  // Insert the element and increment rear
  }
}

// Function to delete an element from the queue
int deleteq(queue *q) {
  // Check if the queue is empty
  if (isQueueEmpty(q)) {
    printf("\nUnderflow!!!\n");  // Queue is empty, cannot delete
    return -1;  // Indicate error
  } else {
    // Retrieve the front element and increment front
    int x = q->x[q->front++];
    return x;  // Return the removed element
  }
}

// Function to display the elements of the queue
void displayq(queue q) {
  // Check if the queue is empty
  if (isQueueEmpty(&q)) {
    printf("\nQueue is Empty!!!\n");  // Queue is empty, nothing to display
  } else {
    printf("\nQueue is:\n");
    // Display all elements from front to rear
    for (int i = q.front; i < q.rear; i++) {
      printf("%d\n", q.x[i]);
    }
  }
}

// Main function to test the queue operations
int main() {
  queue q;        // Declare a queue variable
  initializeQueue(&q);  // Initialize the queue

  int ch, x, flag = 1;  // Variables for user choice, input, and loop control
  while (flag) {
    // Display menu options
    printf("\n\n1. Insert Queue\n2. Delete Queue\n3. Display Queue\n4. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);  // Get user choice

    switch (ch) {
      case 1:
        printf("\nEnter the Element: ");
        scanf("%d", &x);  // Get element to insert
        insertq(&q, x);   // Insert the element
        break;
      case 2:
        x = deleteq(&q);  // Delete an element
        if (x != -1) {
          printf("\nRemoved %d from the Queue\n", x);  // Display removed element
        }
        break;
      case 3:
        displayq(q);  // Display queue elements
        break;
      case 4:
        flag = 0;  // Exit the loop
        break;
      default:
        printf("\nWrong choice!!! Try Again.\n");  // Invalid choice
        break;
    }
  }

  return 0;  // End of program
}

/*
queue: [ , , , , , , , , , , , , , , , , , , , ]  // Empty queue
Front: 0
Rear:  0

queue: [10, , , , , , , , , , , , , , , , , , , ]  // Insert 10 at index 0
Front: 0
Rear:  1

queue: [10, 20, , , , , , , , , , , , , , , , , , ]  // Insert 20 at index 1
Front: 0
Rear:  2

queue: [10, 20, 30, , , , , , , , , , , , , , , , , ]  // Insert 30 at index 2
Front: 0
Rear:  3

queue: [10, 20, 30, , , , , , , , , , , , , , , , , ]  // 10 is removed
Front: 1
Rear:  3

queue: [10, 20, 30, 40, , , , , , , , , , , , , , , , ]  // 20 is removed
Front: 2
Rear:  4
*/




