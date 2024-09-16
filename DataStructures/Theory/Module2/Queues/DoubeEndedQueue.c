#include <stdio.h>
#define SIZE 6  // Size of the deque

typedef struct {
  int arr[SIZE];  // Array to store deque elements
  int front;      // Front pointer
  int rear;       // Rear pointer
} Deque;

void initDeque(Deque *dq) {
  dq->front = -1;  // Initialize front
  dq->rear = -1;   // Initialize rear
}

int isFull(Deque *dq) {
  return ((dq->front == 0 && dq->rear == SIZE - 1) || (dq->front == dq->rear + 1));  // Full when rear wraps around to front
}

int isEmpty(Deque *dq) {
  return (dq->front == -1);  // Empty when front is uninitialized
}

void insertFront(Deque *dq, int value) {
  if (isFull(dq)) {
    printf("Deque is full.\n");
    return;
  }

  if (dq->front == -1) {  // First element being added
    dq->front = 0;
    dq->rear = 0;
   } else if (dq->front == 0) {  // Circularly wrap front pointer
    dq->front = SIZE - 1;
  } else {
    dq->front--;
  }

  dq->arr[dq->front] = value;
}

void insertRear(Deque *dq, int value) {
  if (isFull(dq)) {
    printf("Deque is full.\n");
    return;
  }

  if (dq->front == -1) {  // First element being added
    dq->front = 0;
    dq->rear = 0;
  } else if (dq->rear == SIZE - 1) {  // Circularly wrap rear pointer
    dq->rear = 0;
  } else {
    dq->rear++;
  }

  dq->arr[dq->rear] = value;
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deleted from front: %d\n", dq->arr[dq->front]);

    if (dq->front == dq->rear) {  // Only one element was present
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == SIZE - 1) {  // Circularly wrap front pointer
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deleted from rear: %d\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear) {  // Only one element was present
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0) {  // Circularly wrap rear pointer
        dq->rear = SIZE - 1;
    } else {
        dq->rear--;
    }
}

void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % SIZE;  // Circular wrap
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertFront(&dq, 3);
    
    display(&dq);

    deleteFront(&dq);
    display(&dq);

    deleteRear(&dq);
    display(&dq);

    insertRear(&dq, 15);
    display(&dq);

    return 0;
}
