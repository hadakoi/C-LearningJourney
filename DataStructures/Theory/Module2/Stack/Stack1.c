#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100  /* Maximum stack size */

typedef struct {
  int key;  /* Other fields can be added here */
} element;

element stack[MAX_STACK_SIZE];  /* Stack array of 'element' type */
int top = -1;                   /* Top of the stack initialized to -1 */

/* Function to check if the stack is empty */
int isEmpty() {
  return top == -1;
}

/* Function to check if the stack is full */
int isFull() {
  return top == MAX_STACK_SIZE - 1;
}

/* Function to push an element onto the stack */
void push(element item) {
  if (isFull()) {
    printf("Error: Stack Overflow\n");
    return;
  }
  stack[++top] = item;  // Increment top, then push the element
  printf("Pushed element with key: %d\n", item.key);
}

/* Function to pop an element from the stack */
element pop() {
  if (isEmpty()) {
    printf("Error: Stack Underflow\n");
    exit(EXIT_FAILURE);  // Terminate the program
  }
  return stack[top--];  // Return top element and then decrement top
}

/* Function to display the stack */
void display() {
  if (isEmpty()) {
    printf("The stack is empty.\n");
    return;
  }
  printf("Stack elements:\n");
  for (int i = top; i >= 0; i--) {
    printf("Key: %d\n", stack[i].key);
  }
}

/* Main function to demonstrate stack operations */
int main() {
  element item;
  int choice;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:  // Push
        printf("Enter key to push: ");
        scanf("%d", &item.key);
        push(item);
        break;

      case 2:  // Pop
        item = pop();
        printf("Popped element with key: %d\n", item.key);
        break;

      case 3:  // Display
        display();
        break;

      case 4:  // Exit
        exit(0);

      default:
        printf("Invalid choice, please try again.\n");
    }
  }

  return 0;
}
