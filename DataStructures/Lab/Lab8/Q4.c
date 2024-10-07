#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} queue;

void init(queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(queue *q) {
    return q->front == -1;
}

int isFull(queue *q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(queue *q, int x) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = x;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int x = q->arr[q->front];
    if (q->front == q->rear) {
        init(q);
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return x;
}

void display(queue q) {
    if (isEmpty(&q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q.front;
    while (1) {
        printf(" %d ", q.arr[i]);
        if (i == q.rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void reverse(queue *q) {
    if (isEmpty(q)) return;
    
    int x = dequeue(q); 
    reverse(q); 
    enqueue(q, x); 
}

int main() {
    queue q;
    init(&q);
    int n, x;
    printf("Enter size of queue: ");
    scanf("%d", &n);
    printf("Enter elements of queue: ");
    while (n--) {
        scanf("%d", &x);
        enqueue(&q, x);
    }
    printf("Your Queue: ");
    display(q);
    reverse(&q);
    printf("Reversed Queue: ");
    display(q);
    return 0;
}
