/*
Determine whether a given string is palindrome or not using stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 

typedef struct {
   char arr[MAX];
   int top;
} STACK;

void initialize(STACK *stack) {
   stack->top = -1;
}

int isEmpty(STACK *stack) {
   return stack->top == -1;
}

int isFull(STACK *stack) {
   return stack->top == MAX - 1;
}

void push(STACK *stack, char element) {
   if (isFull(stack)) {
      printf("Error: Stack Overflow\n");
      return;
   }
   stack->arr[++stack->top] = element;
}

char pop(STACK *stack) {
   if (isEmpty(stack)) {
      printf("Error: Stack Underflow\n");
      exit(EXIT_FAILURE);
   }
   return stack->arr[stack->top--];
}

int isPalindrome(char str[]) {
   STACK stack;
   initialize(&stack);
    
   int length = strlen(str);
    
   for (int i = 0; i < length; i++) {
      push(&stack, str[i]);
   }
   
   for (int i = 0; i < length; i++) {
      if (pop(&stack) != str[i]) {
         return 0;
      }
   }
   return 1; 
}

int main() {
   char str[MAX];
    
   printf("Enter a string: ");
   gets(str);
    
   if (isPalindrome(str)) {
      printf("The string \"%s\" is a palindrome.\n", str);
   } 
   else {
      printf("The string \"%s\" is not a palindrome.\n", str);
   }
    
   return 0;
}
