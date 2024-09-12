#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
  int top;
  char items[MAX][MAX];
} Stack;

// Initialize stack
void initStack(Stack* s) {
  s->top = -1;
}

// Push function
void push(Stack* s, const char* item) {
  if (s->top < MAX - 1) {
    s->top++;
    strcpy(s->items[s->top], item);
  } else {
    printf("Stack overflow\n");
  }
}

// Pop function
void pop(Stack* s, char* item) {
  if (s->top >= 0) {
    strcpy(item, s->items[s->top]);
    s->top--;
  } else {
    printf("Stack underflow\n");
  }
}

// Check if character is an operator
int isOperator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Reverse a string
void reverse(char* str) {
  int length = strlen(str);
  for (int i = 0; i < length / 2; i++) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
}

// Convert prefix expression to postfix
void prefixToPostfix(char* prefix, char* postfix) {
  Stack stack;
  initStack(&stack);

  // Reverse the prefix expression
  reverse(prefix);

  char temp[MAX];
  char operand1[MAX], operand2[MAX];

  for (int i = 0; i < strlen(prefix); i++) {
    if (isOperator(prefix[i])) {
      // Operator: pop two operands and combine
      pop(&stack, operand1);
      pop(&stack, operand2);

      sprintf(temp, "%s %s %c", operand1, operand2, prefix[i]);
      push(&stack, temp);
    } else {
      // Operand: push to stack
      temp[0] = prefix[i];
      temp[1] = '\0';
      push(&stack, temp);
    }
  }

  // The final postfix expression is the top of the stack
  strcpy(postfix, stack.items[stack.top]);
}

int main() {
  char prefix[MAX] = "*-A/BC-/AKL";
  char postfix[MAX];

  prefixToPostfix(prefix, postfix);
  printf("Postfix expression: %s\n", postfix);

  return 0;
}
