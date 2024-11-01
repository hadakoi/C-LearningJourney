#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} *NODE;

typedef struct Queue {
  NODE front;
  NODE rear;
} *QUEUE;

QUEUE createQueue() {
  QUEUE queue = (QUEUE)malloc(sizeof(struct Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

void enqueue(QUEUE queue, int value) {
  NODE newNode = (NODE)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  if (queue->rear == NULL) {
    queue->front = queue->rear = newNode;
    return;
  }
    
  queue->rear->next = newNode;
  queue->rear = newNode;
}

int dequeue(QUEUE queue) {
  if (queue->front == NULL) {
    printf("Queue is empty.\n");
    return -1;
  }

  NODE temp = queue->front;
  int data = temp->data;
  queue->front = queue->front->next;

  if (queue->front == NULL)
    queue->rear = NULL;

  free(temp);
  return data;
}

int isEmpty(QUEUE queue) {
  return queue->front == NULL;
}

void displayQueue(QUEUE queue) {
  NODE temp = queue->front;
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() {
  QUEUE queue = createQueue();

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);

  printf("Queue after enqueue operations:\n");
  displayQueue(queue);

  printf("Dequeued element: %d\n", dequeue(queue));
  printf("Queue after dequeue operation:\n");
  displayQueue(queue);

  return 0;
}
