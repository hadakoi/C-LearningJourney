/*
Implement a menu driven program to define a stack of characters. Include push, pop and display functions. 
Also include functions for checking error conditions such as underflow and overflow (ref. figure 1) by defining isEmpty and isFull functions.
Use these function in push, pop and display functions appropriately. Use type defined structure to define a STACK containing a
character array and an integer top. Do not use global variables.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

typedef struct {
   char arr[MAX];
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

void push(STACK *stack, char element) {
   if (isFull(stack)) {
      printf("Error: Stack Overflow\n");
      return;
   }
   stack->arr[++stack->top] = element;
   printf("Pushed '%c' onto the stack.\n", element);
}

void pop(STACK *stack) {
   if (isEmpty(stack)) {
      printf("Error: Stack Underflow\n");
      return;
   }
   char poppedElement = stack->arr[stack->top--];
   printf("Popped '%c' from the stack.\n", poppedElement);
}

void display(STACK *stack) {
   if (isEmpty(stack)) {
      printf("The stack is empty.\n");
      return;
   }
   printf("Stack elements:\n");
   for (int i = stack->top; i >= 0; i--) {
      printf("%c\n", stack->arr[i]);
   }
}

int main() {
   STACK stack;
   initialize(&stack);
    
   int choice;
   char element;
    
   while (1) {
      printf("\nMenu:\n");
      printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
        
      switch (choice) {
         case 1:
            printf("Enter a character to push: ");
            scanf(" %c", &element);
            push(&stack, element);
            break;
         case 2:
            pop(&stack);
            break;
         case 3:
            display(&stack);
            break;
         case 4:
            exit(0);
         default:
            printf("Invalid choice, please try again.\n");
      }
   }
    
   return 0;
}
