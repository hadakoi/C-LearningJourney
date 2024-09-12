#include <stdio.h>
#include <stdlib.h>

#define Max 50

typedef struct {
    int top;
    int arr[Max];  // Use int instead of char for evaluating numbers
} Stack;

void InitStack(Stack *stack) {
    stack->top = -1;
}

int ifFull(Stack *stack) {
    return stack->top == Max - 1;
}

int ifEmpty(Stack *stack) {
    return stack->top == -1;
}

void Push(Stack *stack, int value) {
    if (ifFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int Pop(Stack *stack) {
    if (ifEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
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
int EvaluatePrefix(char *prefix) {
    Stack stack;
    InitStack(&stack);
    int i;
    int length = 0;

    // Determine the length of the prefix expression
    while (prefix[length] != '\0') {
        length++;
    }

    // Process the prefix expression from right to left
    for (i = length - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isDigit(ch)) {
            // Operand: push to stack
            Push(&stack, charToInt(ch));  // Convert char to int
        } else if (isOperator(ch)) {
            // Operator: pop two operands, apply operator, and push result
            int operand1 = Pop(&stack);
            int operand2 = Pop(&stack);
            int result;

            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default: 
                    printf("Unknown operator: %c\n", ch);
                    exit(1);
            }

            Push(&stack, result);
        }
    }

    // The final result is the top of the stack
    return Pop(&stack);
}

int main() {
    char prefix[] = "*+23-45";
    int result = EvaluatePrefix(prefix);
    printf("The result of the prefix expression is: %d\n", result);
    return 0;
}

