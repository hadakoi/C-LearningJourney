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

  // Traverse the prefix expression from right to left
  for (int i = length - 1; i >= 0; i--) {
    char ch = prefix[i];

    // If the character is an operand (assuming single-digit operands)
    if (ch >= '0' && ch <= '9') {
      char* operand = (char*)malloc(2 * sizeof(char));
      operand[0] = ch;
      operand[1] = '\0';
      push(&stack, operand);
    }
    // If the character is an operator
    else if (isOperator(ch)) {
      char* operand1 = pop(&stack);
      char* operand2 = pop(&stack);

      // Create a new string for the postfix expression
      char* postfix = (char*)malloc(strlen(operand1) + strlen(operand2) + 2);
      strcpy(postfix, operand1);
      strcat(postfix, operand2);
      strcat(postfix, &ch);  // Append the operator

      // Push the result back onto the stack
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
  if (postfix != NULL) {
    printf("Postfix expression: %s\n", postfix);
    free(postfix);
  }

  return 0;
}
