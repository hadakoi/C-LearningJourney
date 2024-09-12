#include <stdio.h>
#include <ctype.h> // For isdigit function

#define MAX 20

typedef struct {
  int data[MAX];
  int top;
} stack;

// Initialize the stack
void init(stack *s) {
  s->top = -1;
}

// Check if the stack is empty
int empty(stack *s) {
  return s->top == -1;
}

// Check if the stack is full
int full(stack *s) {
  return s->top == MAX - 1;
}

// Push an element onto the stack
void push(stack *s, int x) {
  if (full(s)) {
    printf("Stack is full\n");
    return;
  }
  s->data[++(s->top)] = x;
}

// Pop an element from the stack
int pop(stack *s) {
  if (empty(s)) {
    printf("Stack is empty\n");
    return -1; // Assuming -1 is an invalid value in context
  }
  return s->data[(s->top)--];
}

// Evaluate the result of an operation
int evaluate(char op, int op1, int op2) {
  switch(op) {
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '*': return op1 * op2;
    case '/': return op1 / op2;
    case '%': return op1 % op2;
    default: printf("Invalid operator\n"); return 0;
  }
}

int main() {
  stack s;
  char x;
  int op1, op2, val;

  init(&s);
  printf("Enter the prefix expression (e.g., *+593):\n(single digit operands and operators only): ");

  // Read the prefix expression from right to left
  // To simulate reading from right to left, we use a reverse input approach
  char expression[MAX];
  int length = 0;

  // Read the entire expression
  while ((x = getchar()) != '\n') {
    expression[length++] = x;
  }
  expression[length] = '\0'; // Null-terminate the string

  // Process the expression from right to left
  for (int i = length - 1; i >= 0; i--) {
    x = expression[i];
    if (isdigit(x)) {
      push(&s, x - '0'); // Convert char digit to integer
    } else {
        op1 = pop(&s);
        op2 = pop(&s);
        val = evaluate(x, op1, op2);
        push(&s, val);
      }
    }

  val = pop(&s);
  printf("Value of expression = %d\n", val);

  return 0;
}
