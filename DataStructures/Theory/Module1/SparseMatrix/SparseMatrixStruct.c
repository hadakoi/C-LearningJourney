/*
0 0 3 0 4
0 0 5 7 0
0 0 0 0 0
0 2 6 0 0
*/


#include <stdio.h>

// Define a structure to represent a non-zero element in the sparse matrix
typedef struct {
    int row;    // Row index of the non-zero element
    int col;    // Column index of the non-zero element
    int value;  // Value of the non-zero element
} SparseElement;

int main() {
  // Example sparse matrix with 4 non-zero elements
  SparseElement sparseMatrix[] = {
    {0, 2, 3},  // Element at (0, 2) with value 3
    {0, 4, 4},  // Element at (0, 4) with value 4
    {1, 2, 5},  // Element at (1, 2) with value 5
    {1, 3, 7},  // Element at (1, 3) with value 7
    {3, 1, 2},  // Element at (3, 1) with value 2
    {3, 2, 6}   // Element at (3, 2) with value 6
  };

  int numElements = sizeof(sparseMatrix) / sizeof(sparseMatrix[0]);

  printf("Sparse Matrix Representation (Array):\n");
  for (int i = 0; i < numElements; i++) {
    printf("Row: %d, Column: %d, Value: %d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
  }

  return 0;
}
