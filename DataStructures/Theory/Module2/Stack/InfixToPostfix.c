#include <stdio.h>
#include <stdlib.h>
#define MAX 100


typedef struct {
  int top;
  char arr[MAX];
} Stack;

void StackInit(Stack *Stack){
  Stack->top = -1;
}

int ifFull(Stack *Stack){
  return Stack->top == MAX -1;
}

int ifEmpty(Stack *Stack){
  return Stack->top == -1;
}

void push(Stack *Stack, char Item){
  if(ifFull(Stack)){
    printf("Stack Overflow\n");
    return;
  }
  Stack->arr[++Stack->top] = Item;
}

char pop(Stack *Stack){
  if(ifEmpty(Stack)){
    printf("Stack Underflow\n");
    return '\0';
  }
  return Stack->arr[Stack->top--];
}

int precedence(char op){
  switch (op){
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return 0;
  }
}

void InfixToPostfix(char *infix, char *postfix){
  Stack stack;
  StackInit(&stack);
  int k = 0;
  for(int i = 0; infix[i] != '\0'; i++){
    char ch = infix[i];
    if('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || '0' <= ch && ch <= '9'){
      postfix[k++] = ch;
    }
    else if (ch == '('){
      push(&stack, ch);
    }
    else if(ch == ')'){
      while(!ifEmpty(&stack) && stack.arr[stack.top] != '('){
        postfix[k++] = pop(&stack);
      }
      pop(&stack);
    }
    else{
      while(!ifEmpty(&stack) && precedence(ch) <= precedence(stack.arr[stack.top])){
        postfix[k++] = pop(&stack);
      }
      push(&stack, ch);
    }
  }
  while(!ifEmpty(&stack)){
      postfix[k++] = pop(&stack);
  }
  postfix[k++] = '\0';
}

int main() {
  char infix[MAX] = "A+B^(C+D-E)";
  char postfix[MAX];
  
  InfixToPostfix(infix, postfix);
  
  printf("Postfix Expression: %s\n", postfix);
  
  return 0;
}