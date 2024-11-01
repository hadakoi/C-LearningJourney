#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} *NODE;

NODE createNode(int value) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertIteratively(NODE *root, int value) {
    NODE newNode = createNode(value);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    NODE current = *root;
    NODE parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (value < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void inOrderTraversalIterative(NODE root) {
    NODE stack[100];
    int top = -1;

    NODE current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preOrderTraversalIterative(NODE root) {
    if (root == NULL) return;
    
    NODE stack[100];
    int top = -1;
    
    stack[++top] = root;

    while (top != -1) {
        NODE current = stack[top--];
        printf("%d ", current->data);

        if (current->right) {
            stack[++top] = current->right;
        }
        if (current->left) {
            stack[++top] = current->left;
        }
    }
}

void postOrderTraversalIterative(NODE root) {
    if (root == NULL) return;
    
    NODE stack[100];
    int top = -1;
    NODE lastVisited = NULL;

    stack[++top] = root;

    while (top != -1) {
        NODE current = stack[top];

        if (current->left == NULL && current->right == NULL || 
            (lastVisited != NULL && (lastVisited == current->left || lastVisited == current->right))) {
            printf("%d ", current->data);
            lastVisited = stack[top--];
        } else {
            if (current->right) {
                stack[++top] = current->right;
            }
            if (current->left) {
                stack[++top] = current->left;
            }
        }
    }
}

void levelOrderTraversal(NODE root) {
    if (root == NULL) return;

    NODE queue[100];
    int front = 0, rear = -1;

    queue[++rear] = root;

    while (front <= rear) {
        NODE current = queue[front++];
        printf("%d ", current->data);

        if (current->left) {
            queue[++rear] = current->left;
        }
        if (current->right) {
            queue[++rear] = current->right;
        }
    }
}

int main() {
    NODE root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Level-Order Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertIteratively(&root, value);
                break;
            case 2:
                printf("In-Order Traversal: ");
                inOrderTraversalIterative(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-Order Traversal: ");
                preOrderTraversalIterative(root);
                printf("\n");
                break;
            case 4:
                printf("Post-Order Traversal: ");
                postOrderTraversalIterative(root);
                printf("\n");
                break;
            case 5:
                printf("Level-Order Traversal: ");
                levelOrderTraversal(root);
                printf("\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
