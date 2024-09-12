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
        return -1; // Indicating an error
    }
    return stack->arr[stack->top--];
}

int Precedence(char a) {
    switch(a) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void ReverseString(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void SwapParentheses(char *str) {
    for(int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

void InfixToPostfix(char *infix, char *postfix) {
    Stack stack;
    int k = 0;
    initStack(&stack);

    for(int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        } else if(ch == '(') {
            Push(&stack, ch);
        } else if(ch == ')') {
            while(!ifEmpty(&stack) && stack.arr[stack.top] != '(') {
                postfix[k++] = Pop(&stack);
            }
            Pop(&stack); // Remove '(' from stack
        } else {
            while(!ifEmpty(&stack) && Precedence(stack.arr[stack.top]) >= Precedence(ch)) {
                postfix[k++] = Pop(&stack);
            }
            Push(&stack, ch);
        }
    }

    while(!ifEmpty(&stack)) {
        postfix[k++] = Pop(&stack);
    }

    postfix[k++] = '\0';
}

void InfixToPrefix(char *infix, char *prefix) {
    char reversedInfix[Max];
    char postfix[Max];
    
    // Reverse the infix expression and swap parentheses
    strcpy(reversedInfix, infix);
    ReverseString(reversedInfix);
    SwapParentheses(reversedInfix);

    // Convert reversed infix to postfix
    InfixToPostfix(reversedInfix, postfix);

    // Reverse postfix to get prefix
    ReverseString(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[] = "a+b*(c-d)";
    char prefix[Max];

    InfixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
