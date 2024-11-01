#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} *NODE;

NODE createNode(char data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

NODE constructExpressionTree(char *postfix) {
    NODE stack[100]; // Stack to hold tree nodes
    int top = -1;    // Stack pointer

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            stack[++top] = createNode(postfix[i]);
        } else if (isOperator(postfix[i])) {
            NODE newNode = createNode(postfix[i]);
            newNode->right = stack[top--]; // Pop top two nodes
            newNode->left = stack[top--];
            stack[++top] = newNode; // Push new node onto stack
        }
    }
    return stack[top]; // The root of the expression tree
}

int evaluate(NODE root) {
    if (root == NULL) {
        return 0;
    }

    // Leaf node (operand)
    if (!isOperator(root->data)) {
        return root->data - '0'; // Convert char to int
    }

    // Evaluate left and right subtrees
    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);

    switch (root->data) {
        case '+':
            return leftEval + rightEval;
        case '-':
            return leftEval - rightEval;
        case '*':
            return leftEval * rightEval;
        case '/':
            return leftEval / rightEval;
    }
    return 0;
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    NODE root = constructExpressionTree(postfix);
    
    printf("The evaluation of the expression tree is: %d\n", evaluate(root));

    return 0;
}
