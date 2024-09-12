#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure for handling integers
typedef struct {
    int top;
    int items[MAX];
} Stack;

// Initialize stack
void initStack(Stack* s) {
    s->top = -1;
}

// Push function
void push(Stack* s, int item) {
  if (s->top < MAX - 1) {
    s->top++;
    s->items[s->top] = item;
  } else {
      printf("Stack overflow\n");
  }
}

// Pop function
int pop(Stack* s) {
  if (s->top >= 0) {
    return s->items[s->top--];
  } else {
    printf("Stack underflow\n");
    return -1;  // Return an invalid value to indicate error
  }
}

// Check if character is an operator
int isOperator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Check if character is a digit
int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Convert character to integer
int charToInt(char ch) {
  return ch - '0';
}

// Evaluate prefix expression
int evaluatePrefix(const char* prefix) {
  Stack stack;
  initStack(&stack);

  int length = strlen(prefix);

  for (int i = length - 1; i >= 0; i--) {
    char ch = prefix[i];

    if (isDigit(ch)) {
    // Operand: push to stack
      push(&stack, charToInt(ch));  // Convert char to int
    } else if (isOperator(ch)) {
      // Operator: pop two operands, apply operator, and push result
      int operand1 = pop(&stack);
      int operand2 = pop(&stack);

      int result;
      switch (ch) {
        case '+': result = operand1 + operand2; break;
        case '-': result = operand1 - operand2; break;
        case '*': result = operand1 * operand2; break;
        case '/': result = operand1 / operand2; break;
        default: result = 0; break;
      }

      push(&stack, result);
    }
  }

  // The final result is the top of the stack
  return pop(&stack);
}

int main() {
    char prefix[MAX] = "*+23-45";
    int result = evaluatePrefix(prefix);
    printf("Prefix expression evaluates to: %d\n", result);

    return 0;
}
