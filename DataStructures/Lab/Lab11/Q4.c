#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} *NODE;

// Function to create a new tree node
NODE createNode(int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// a) Function to create a copy of a binary tree
NODE copyTree(NODE root) {
    if (root == NULL) {
        return NULL; // Base case: if the tree is empty, return NULL
    }

    // Create a new node with the same data as the root
    NODE newRoot = createNode(root->data);
    
    // Recursively copy the left and right subtrees
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);

    return newRoot; // Return the new tree
}

// b) Function to test for equality of two binary trees
int areEqual(NODE root1, NODE root2) {
    // If both trees are empty, they are equal
    if (root1 == NULL && root2 == NULL) {
        return 1; // Trees are equal
    }

    // If one of the trees is empty and the other is not, they are not equal
    if (root1 == NULL || root2 == NULL) {
        return 0; // Trees are not equal
    }

    // Check if the data of the current nodes are equal and recursively check subtrees
    return (root1->data == root2->data) &&
           areEqual(root1->left, root2->left) &&
           areEqual(root1->right, root2->right);
}

// Function to print in-order traversal of the binary tree
void inorderTraversal(NODE root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    // Example binary tree
    NODE root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    printf("Original Tree (In-order): ");
    inorderTraversal(root1);
    printf("\n");

    // Copy the binary tree
    NODE root2 = copyTree(root1);
    printf("Copied Tree (In-order): ");
    inorderTraversal(root2);
    printf("\n");

    // Check for equality
    if (areEqual(root1, root2)) {
        printf("The two trees are equal.\n");
    } else {
        printf("The two trees are not equal.\n");
    }

    // Modify the copied tree to demonstrate inequality
    root2->right->data = 99; // Change a value to make the trees unequal
    if (areEqual(root1, root2)) {
        printf("The two trees are equal.\n");
    } else {
        printf("The two trees are not equal.\n");
    }

    return 0;
}
