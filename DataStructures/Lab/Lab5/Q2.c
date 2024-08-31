/*
Convert a given decimal number to binary using stack. no stdbool.h
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 32

typedef struct {
    int arr[MAX];
    int top;
} STACK;

void initialize(STACK *stack) {
    stack->top = -1;
}

int isEmpty(STACK *stack) {
    return stack->top == -1;
}

int isFull(STACK *stack) {
    return stack->top == MAX - 1;
}

void push(STACK *stack, int element) {
   if (isFull(stack)) {
      printf("Error: Stack Overflow\n");
      return;
   }
   stack->arr[++stack->top] = element;
}

int pop(STACK *stack) {
   if (isEmpty(stack)) {
      printf("Error: Stack Underflow\n");
      exit(EXIT_FAILURE);
   }
   return stack->arr[stack->top--];
}

void decimalToBinary(int decimal) {
   STACK stack;
   initialize(&stack);
    
   while (decimal > 0) {
      int remainder = decimal % 2;
      push(&stack, remainder);
      decimal /= 2;
   }
    
   printf("Binary equivalent: ");
   while (!isEmpty(&stack)) {
      printf("%d", pop(&stack));
   }
   printf("\n");
}

int main() {
   int decimal;
    
   printf("Enter a decimal number: ");
   scanf("%d", &decimal);
    
   if (decimal == 0) {
      printf("Binary equivalent: 0\n");
   } else {
      decimalToBinary(decimal);
   }
    
   return 0;
}
