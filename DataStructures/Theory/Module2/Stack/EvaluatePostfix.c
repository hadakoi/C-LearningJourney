#include <stdio.h>

#define MAX 20

typedef struct {
  int data[MAX];
  int top;
} stack;

void init(stack *s) {
  s->top = -1;
}

int empty(stack *s) {
  return s->top == -1;
}

int full(stack *s) {
  return s->top == MAX - 1;
}

void push(stack *s, int x) {
  if (full(s)) {
    printf("Stack is full\n");
    return;
  }
  s->data[++(s->top)] = x;
}

int pop(stack *s) {
  if (empty(s)) {
    printf("Stack is empty\n");
    return -1; 
  }
  return s->data[(s->top)--];
}


int is_digit(char ch) {
  return ch >= '0' && ch <= '9';
}

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
  char expression[MAX];
  char x;
  int op1, op2, val;
  
  init(&s);
  printf("Enter the postfix expression (e.g., 59+3*):\n(single digit operands and operators only): ");

  scanf("%s", expression);
  
  for (int i = 0; expression[i] != '\0'; i++) {
    x = expression[i];
    if (is_digit(x)) {
      push(&s, x - '0'); // Convert char digit to integer
    } else {
      op2 = pop(&s);
      op1 = pop(&s);
      val = evaluate(x, op1, op2);
      push(&s, val);
    }
  }

  val = pop(&s);
  printf("Value of expression = %d\n", val);
  
  return 0;
}
