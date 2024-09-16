#include <stdio.h>

#define SIZE 6  // Max size of the priority queue

// Enum for vehicle types with their associated priorities
typedef enum {
    EMERGENCY = 10,
    FIRE = 9,
    SCHOOL = 8,
    PRESIDENT = 7,
    NORMAL = 6
} VehicleType;

// Struct for vehicle with type and ID
typedef struct {
    int id;          // Vehicle ID
    VehicleType type; // Vehicle type (priority)
} Vehicle;

// Priority queue struct with front and rear pointers
typedef struct {
    Vehicle arr[SIZE];  // Array to hold vehicles
    int front;  // Front pointer
    int rear;   // Rear pointer
} PriorityQueue;

void initQueue(PriorityQueue *pq) {
    pq->front = 0;
    pq->rear = 0;
}

int isEmpty(PriorityQueue *pq) {
    return pq->front == pq->rear;
}

int isFull(PriorityQueue *pq) {
    return pq->rear == SIZE;
}

void enqueue(PriorityQueue *pq, int id, VehicleType type) {
    if (isFull(pq)) {
        printf("Priority queue is full.\n");
        return;
    }
    pq->arr[pq->rear].id = id;
    pq->arr[pq->rear].type = type;
    pq->rear++;
}

void dequeue(PriorityQueue *pq) {
  if (isEmpty(pq)) {
    printf("Priority queue is empty.\n");
    return;
  }

  // Find the vehicle with the highest priority
  int highestPriorityIndex = pq->front;
  for (int i = pq->front + 1; i < pq->rear; i++) {
    if (pq->arr[i].type > pq->arr[highestPriorityIndex].type) {
      highestPriorityIndex = i;
    }
  }

  // Dequeue the vehicle with the highest priority
  printf("Dequeued Vehicle ID: %d with Priority: %d\n", pq->arr[highestPriorityIndex].id, pq->arr[highestPriorityIndex].type);

  // Shift the elements to fill the gap
  for (int i = highestPriorityIndex; i < pq->rear - 1; i++) {
    pq->arr[i] = pq->arr[i + 1];
  }
  pq->rear--;  // Decrease the rear pointer
}

// Display the queue
void display(PriorityQueue *pq) {
  if (isEmpty(pq)) {
    printf("Priority queue is empty.\n");
    return;
  }

  printf("Queue elements (Vehicle ID, Type/ Priority):\n");
  for (int i = pq->front; i < pq->rear; i++) {
    printf("Vehicle ID: %d, Priority: %d\n", pq->arr[i].id, pq->arr[i].type);
  }
}

int main() {
  PriorityQueue pq;
  initQueue(&pq);

  // Enqueue vehicles with different IDs and types (priorities)
  enqueue(&pq, 101, FIRE);       // Fire truck with priority 9
  enqueue(&pq, 102, SCHOOL);     // School bus with priority 8
  enqueue(&pq, 103, EMERGENCY);  // Emergency vehicle with priority 10
  enqueue(&pq, 104, PRESIDENT);  // President's car with priority 7
  enqueue(&pq, 105, NORMAL);     // Normal vehicle with priority 6

  // Display the priority queue
  display(&pq);

  // Dequeue the vehicle with the highest priority
  dequeue(&pq);
  display(&pq);  // Display after dequeuing

  // Enqueue another vehicle
  enqueue(&pq, 106, EMERGENCY);  // Another emergency vehicle with priority 10
  display(&pq);  // Display after new enqueue

  return 0;
}
