#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int front, rear;
} Deque;

void init(Deque *dq) {
    dq->front = dq->rear = -1;
}

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

int isFull(Deque *dq) {
    return (dq->rear + 1) % MAX == dq->front;
}

void enqueueR(Deque *dq, char x) {
    if (isFull(dq)) {
        printf("Error: Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
    }
    dq->rear = (dq->rear + 1) % MAX;
    dq->arr[dq->rear] = x;
}

void enqueueF(Deque *dq, char x) {
    if (isFull(dq)) {
        printf("Error: Deque is full\n");
        return;
    }
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = x;
}

char dequeueF(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Error: Deque is empty\n");
        return '\0';
    }
    char x = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        init(dq);
    } else {
        dq->front = (dq->front + 1) % MAX;
    }
    return x;
}

char dequeueR(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Error: Deque is empty\n");
        return '\0';
    }
    char x = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        init(dq);
    } else {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    return x;
}

int isPalindrome(Deque *dq) {
    Deque temp = *dq;
    while (temp.front != temp.rear) {
        if (dequeueF(&temp) != dequeueR(&temp)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Deque dq;
    init(&dq);
    char s[MAX];
    printf("Enter a string: ");
    fgets(s, MAX, stdin);
    int i;
    for (i = 0; s[i] != '\n' && s[i] != '\0'; i++) {
        enqueueR(&dq, s[i]);
    }
    if (isPalindrome(&dq)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    return 0;
}
