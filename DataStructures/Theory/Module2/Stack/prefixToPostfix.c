#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  char* data[MAX];
  int top;
} Stack;

void initStack(Stack* stack) {
  stack->top = -1;
}

int isEmpty(Stack* stack) {
  return stack->top == -1;
}

int isFull(Stack* stack) {
  return stack->top == MAX - 1;
}

void push(Stack* stack, char* str) {
  if (!isFull(stack)) {
    stack->data[++(stack->top)] = str;
  } else {
    printf("Stack overflow\n");
  }
}

char* pop(Stack* stack) {
  if (!isEmpty(stack)) {
    return stack->data[(stack->top)--];
  } else {
    printf("Stack underflow\n");
    return NULL;
  }
}

int isOperator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

char* prefixToPostfix(char* prefix) {
  Stack stack;
  initStack(&stack);
  int length = strlen(prefix);

  // Process the prefix expression from right to left
  for (int i = length - 1; i >= 0; i--) {
    char ch = prefix[i];

    if (ch >= '0' && ch <= '9') {
      char* operand = (char*)malloc(2 * sizeof(char));
      operand[0] = ch;
      operand[1] = '\0';
      push(&stack, operand);
    } else if (isOperator(ch)) {
      char* operand1 = pop(&stack);
      char* operand2 = pop(&stack);

      char* postfix = (char*)malloc(strlen(operand1) + strlen(operand2) + 3);
      strcpy(postfix, operand1);
      strcat(postfix, operand2);
      postfix[strlen(postfix)] = ch;
      postfix[strlen(postfix) + 1] = '\0';

      push(&stack, postfix);
    }
  }

  return pop(&stack);
}

int main() {
  char prefix[MAX];

  printf("Enter a prefix expression: ");
  scanf("%s", prefix);

  char* postfix = prefixToPostfix(prefix);
  printf("Postfix expression: %s\n", postfix);
  
  return 0;
}

