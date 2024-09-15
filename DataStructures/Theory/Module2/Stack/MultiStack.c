#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define the maximum size of the array

typedef struct {
    int Array[MAX];
    int top1; // Index for the top of Stack 1
    int top2; // Index for the top of Stack 2
} TwoStacks;

// Initialize the TwoStacks structure
void initialize(TwoStacks *ts) {
    ts->top1 = -1;           // Stack 1 starts from the beginning
    ts->top2 = MAX;          // Stack 2 starts from the end
}

// Push an element into Stack 1
void push1(TwoStacks *ts, int value) {
    // Check if Stack 1 has space
    if (ts->top1 + 1 < ts->top2) {
        ts->Array[++ts->top1] = value;
    } else {
        printf("Stack 1 overflow.\n");
    }
}

// Push an element into Stack 2
void push2(TwoStacks *ts, int value) {
    // Check if Stack 2 has space
    if (ts->top2 - 1 > ts->top1) {
        ts->Array[--ts->top2] = value;
    } else {
        printf("Stack 2 overflow.\n");
    }
}

// Pop an element from Stack 1
int pop1(TwoStacks *ts) {
    // Check if Stack 1 is empty
    if (ts->top1 < 0) {
        printf("Stack 1 is empty.\n");
        return -1; // or some error code
    }
    return ts->Array[ts->top1--];
}

// Pop an element from Stack 2
int pop2(TwoStacks *ts) {
    // Check if Stack 2 is empty
    if (ts->top2 >= MAX) {
        printf("Stack 2 is empty.\n");
        return -1; // or some error code
    }
    return ts->Array[ts->top2++];
}

// Peek at the top element of Stack 1
int peek1(TwoStacks *ts) {
    // Check if Stack 1 is empty
    if (ts->top1 < 0) {
        printf("Stack 1 is empty.\n");
        return -1; // or some error code
    }
    return ts->Array[ts->top1];
}

// Peek at the top element of Stack 2
int peek2(TwoStacks *ts) {
    // Check if Stack 2 is empty
    if (ts->top2 >= MAX) {
        printf("Stack 2 is empty.\n");
        return -1; // or some error code
    }
    return ts->Array[ts->top2];
}

int main() {
  TwoStacks ts;
  initialize(&ts);
    
  push1(&ts, 10);
  push1(&ts, 20);
  push2(&ts, 30);
  push2(&ts, 40);

  printf("Popped from Stack 1: %d\n", pop1(&ts));
  printf("Popped from Stack 2: %d\n", pop2(&ts));
  printf("Top of Stack 1: %d\n", peek1(&ts));
  printf("Top of Stack 2: %d\n", peek2(&ts));

  return 0;
}
