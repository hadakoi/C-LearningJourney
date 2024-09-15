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
  q->front = -1;  // Indicates that the queue is empty
  q->rear = -1;   // Indicates that the queue is empty
}

// Function to check if the queue is full
int isQueueFull(queue *q) {
  // The queue is full if rear has reached the maximum index
  return q->rear == MAX - 1;
}

// Function to check if the queue is empty
int isQueueEmpty(queue *q) {
  // The queue is empty if front is -1
  return q->front == -1;
}

// Function to insert an element into the queue
void insertq(queue *q, int x) {
  // Check if the queue is full
  if (isQueueFull(q)) {
    printf("\nOverflow\n");  // Queue is full, cannot insert
  } else {
    // If the queue was empty before, initialize front
    if (isQueueEmpty(q)) {
      q->front = 0;  // Set front to 0 as this is the first element
    }
    q->x[++q->rear] = x;  // Increment rear and insert the element
  }
}

// Function to delete an element from the queue
int deleteq(queue *q) {
  int x;
  // Check if the queue is empty
  if (isQueueEmpty(q)) {
    printf("\nUnderflow!!!\n");  // Queue is empty, cannot delete
    return -1;  // Indicate error
  } 
  else if (q->front == q->rear) {
    // Queue will be empty after this operation
    x = q->x[q->front];  // Retrieve the front element
    q->front = q->rear = -1;  // Reset front and rear to -1
    return x;  // Return the removed element
  } 
  else {
    // Return the front element and increment front
    return q->x[q->front++];  
  }
}

// Function to display the elements of the queue
void displayq(queue q) {
  int i;
  // Check if the queue is empty
  if (isQueueEmpty(&q)) {
    printf("\nQueue is Empty!!!\n");  // Queue is empty, nothing to display
  } 
  else {
    printf("\nQueue is:\n");
    // Display all elements from front to rear
    for (i = q.front; i <= q.rear; i++) {
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

1. Before insertion:
front = -1
rear = -1
queue = [ , , , , , , , , , , , , , , , , , , , ]

After insertion:
front = 0
rear = 0
queue = [10, , , , , , , , , , , , , , , , , , , ]

2. Before insertion:
front = 0
rear = 0
queue = [10, , , , , , , , , , , , , , , , , , , ]

After insertion:
front = 0
rear = 1
queue = [10, 20, , , , , , , , , , , , , , , , , , ]

3. Before deletion:
front = 0
rear = 1
queue = [10, 20, , , , , , , , , , , , , , , , , , ]

After deletion:
front = 1
rear = 1
queue = [ , 20, , , , , , , , , , , , , , , , , , ]
*/
