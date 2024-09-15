  #include <stdio.h>
#include <stdlib.h>

#define Max 5

typedef struct {
  int top;
  int arr[Max];
} Stack;

void InitStack(Stack *stack) {
  stack->top = -1;
}

int ifFull(Stack *stack) {
  return stack->top == Max - 1;
}

int ifEmpty(Stack *stack) {
  return stack->top == -1;
}

void push(Stack *stack, int item) {
  if (ifFull(stack)) {
    printf("Stack Overflow\n");
    return;
  }
  stack->arr[++stack->top] = item;
}

int Pop(Stack *stack) {
  if (ifEmpty(stack)) {
    printf("Stack Underflow\n");
    return -1;  // Return an invalid value to indicate error
  }
  return stack->arr[stack->top--];
}

void display(Stack *stack) {
  if (ifEmpty(stack)) {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack elements:\n");
  for (int i = stack->top; i >= 0; i--) {
    printf("%d\n", stack->arr[i]);
  }
}

int main() {
  Stack stack;
  InitStack(&stack);

  int choice, item;

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
        printf("Enter an item to push: ");
        scanf("%d", &item);
        push(&stack, item);
        break;
      case 2:
        item = Pop(&stack);
        if (item != -1) {
          printf("Popped item: %d\n", item);
        }
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
