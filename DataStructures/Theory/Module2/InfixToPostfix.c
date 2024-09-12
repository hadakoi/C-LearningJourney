#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 50

typedef struct {
  int top;
  char arr[Max];
} Stack;

void initStack(Stack *stack) {
  stack->top = -1;
}

int ifFull(Stack *stack) {
  return stack->top == Max - 1;
}

int ifEmpty(Stack *stack) {
  return stack->top == -1;
}

void Push(Stack *stack, char value) {
  if (ifFull(stack)) {
    printf("Stack Overflow\n");
    return;
  }
  stack->arr[++stack->top] = value;
}

char Pop(Stack *stack) {
  if (ifEmpty(stack)) {
    printf("Stack Underflow\n");
    return -1;
  }
  return stack->arr[stack->top--];
}

int Precedence(char a){
  switch(a){
    case '+':
    case '-':
      return 1;
      break;
    case '*':
    case '/':
      return 2;
      break;
    case '(':
    case ')':
      return 0;
      break;
    default:
      return -1;
  }
}

void InfixToPostfix(char *infix, char *postfix){
  Stack stack;
  int k = 0;
  initStack(&stack);

  for(int i = 0; infix[i] != '\0'; i++){
    char ch = infix[i];

    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
      postfix[k++] = ch;
    }

    else if(ch == '('){
      Push(&stack, ch);
    }

    else if(ch == ')'){
      while(!ifEmpty(&stack) && stack.arr[stack.top] != '('){
        postfix[k++] = Pop(&stack);
      }
      Pop(&stack);
    }

    else{
      while(!ifEmpty(&stack) && Precedence(stack.arr[stack.top]) >= Precedence(ch)){
        postfix[k++] = Pop(&stack);
      }
      Push(&stack, ch);
    }
  }

  while(!ifEmpty(&stack)){
    postfix[k++] = Pop(&stack);
  }

  postfix[k++] = '\0';
}


int main() {
  char infix[] = "a+b*(c-d)";
  char postfix[Max];

  InfixToPostfix(infix, postfix);
  printf("Postfix Expression: %s\n", postfix);

  return 0;
}