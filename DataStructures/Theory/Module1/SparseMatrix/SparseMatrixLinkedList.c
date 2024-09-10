#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
  int row;         // Row index of the non-zero element
  int col;         // Column index of the non-zero element
  int value;       // Value of the non-zero element
  struct Node* next; // Pointer to the next node
} Node;

// Function to create a new node
Node* createNode(int row, int col, int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->row = row;
  newNode->col = col;
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

// Function to print the linked list representation of the sparse matrix
void printSparseMatrix(Node* head) {
  Node* current = head;
  while (current != NULL) {
    printf("Row: %d, Column: %d, Value: %d\n", current->row, current->col, current->value);
    current = current->next;
  }
}

int main() {
  // Create a linked list for the sparse matrix
  Node* head = createNode(0, 2, 3);  // Element at (0, 2) with value 3
  head->next = createNode(0, 4, 4);  // Element at (0, 4) with value 4
  head->next->next = createNode(1, 2, 5); // Element at (1, 2) with value 5
  head->next->next->next = createNode(1, 3, 7); // Element at (1, 3) with value 7
  head->next->next->next->next = createNode(3, 1, 2); // Element at (3, 1) with value 2
  head->next->next->next->next->next = createNode(3, 2, 6); // Element at (3, 2) with value 6

  printf("Sparse Matrix Representation (Linked List):\n");
  printSparseMatrix(head);

  // Free allocated memory
  Node* current = head;
  Node* next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  return 0;
}
