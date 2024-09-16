#include <stdio.h>
#define SIZE 6  // Size of the queue (1 index for pointers, so actual capacity is SIZE-1)

typedef struct {
    int arr[SIZE];  // 0th index reserved for pointers
    int front;      // Front pointer
    int rear;       // Rear pointer
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = 0;  // Initialize front to 0 (reserved index)
    q->rear = 0;   // Initialize rear to 0 (reserved index)
}

int isFull(CircularQueue *q) {
    return ((q->rear + 1) % SIZE == q->front);  // Queue is full if next position of rear is front
}

int isEmpty(CircularQueue *q) {
    return (q->front == q->rear);  // Queue is empty if front == rear
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->rear = (q->rear + 1) % SIZE;   // Move rear pointer to next position
    q->arr[q->rear] = value;          // Add element to the new rear
}

void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    q->front = (q->front + 1) % SIZE;           // Move front pointer to next position
    printf("Dequeued: %d\n", q->arr[q->front]);  // Remove element from the new front
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = (q->front + 1) % SIZE;
    while (i != (q->rear + 1) % SIZE) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);  // This will make the queue full

    display(&q);  // Display current queue

    dequeue(&q);
    dequeue(&q);

    display(&q);  // Display after two dequeues

    enqueue(&q, 60);
    display(&q);  // Display after enqueuing again

    return 0;
}
