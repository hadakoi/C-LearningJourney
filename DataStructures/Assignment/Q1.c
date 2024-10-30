#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[50];
    int result;
    struct Node *prev, *next;
} *NODE;

NODE head = NULL;

NODE createNode(char *data, int result) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->result = result;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(char *data, int result) {
    NODE newNode = createNode(data, result);
    if (head == NULL) {
        head = newNode;
    } else {
        NODE temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display() {
    NODE temp = head;
    while (temp != NULL) {
        printf("Data: %s", temp->data);
        if (strstr(temp->data, "<") == NULL) {
            printf(", Result: %d", temp->result);
        }
        printf("\n");
        temp = temp->next;
    }
}

int checkExpression(char *expression) {
    int balance = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') balance++;
        else if (expression[i] == ')') balance--;
        if (balance < 0) return 0;
    }
    return balance == 0;
}

int computePostfix(char *expression) {
    int stack[50], top = -1;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            stack[++top] = expression[i] - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            switch (expression[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }
    return stack[top];
}

int computePrefix(char *expression) {
    int stack[50], top = -1;
    int length = strlen(expression);
    for (int i = length - 1; i >= 0; i--) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            stack[++top] = expression[i] - '0';
        } else {
            int a = stack[top--];
            int b = stack[top--];
            switch (expression[i]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }
    return stack[top];
}

void processList() {
    NODE temp = head;
    while (temp != NULL) {
        if (strstr(temp->data, "<POSTFIX>") != NULL || strstr(temp->data, "<PREFIX>") != NULL) {
            if (temp->next != NULL && strstr(temp->next->data, "<") == NULL) {
                if (strstr(temp->data, "<POSTFIX>") != NULL) {
                    if (checkExpression(temp->next->data)) {
                        temp->next->result = computePostfix(temp->next->data);
                    } else {
                        temp->next->result = -1;
                    }
                } else if (strstr(temp->data, "<PREFIX>") != NULL) {
                    if (checkExpression(temp->next->data)) {
                        temp->next->result = computePrefix(temp->next->data);
                    } else {
                        temp->next->result = -1;
                    }
                }
            }
        }
        temp = temp->next;
    }
}

int main() {
    int choice;
    char data[50];
    int result = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert Tag or Expression\n");
        printf("2. Display List\n");
        printf("3. Process List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter tag or expression: ");
                fgets(data, 50, stdin);
                data[strcspn(data, "\n")] = '\0';

                if (strstr(data, "<TEST>") != NULL || strstr(data, "<POSTFIX>") != NULL || strstr(data, "<PREFIX>") != NULL) {
                    insert(data, 0);
                } else {
                    insert(data, result);
                }
                break;

            case 2:
                display();
                break;

            case 3:
                processList();
                printf("List processed and results updated.\n");
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
