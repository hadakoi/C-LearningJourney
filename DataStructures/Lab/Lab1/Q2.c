/*
Check whether the given matrix is sparse matrix or not using functions
*/

#include <stdio.h>

// Function to input the matrix
void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
  printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
       scanf("%d", &matrix[i][j]);
    }
  }
}

// Function to check if the matrix is sparse
int isSparseMatrix(int rows, int cols, int matrix[rows][cols]) {
  int zeroCount = 0;
  int totalElements = rows * cols;

  // Counting zero elements
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {
        zeroCount++;
      }
    }
  }

  // Check if more than half of the elements are zeros
  if (zeroCount > (totalElements / 2)) {
    return 1; // It is a sparse matrix
  } else {
    return 0; // It is not a sparse matrix
  }
}

// Function to display the result
void displayResult(int isSparse) {
  if (isSparse) {
    printf("The matrix is a sparse matrix.\n");
  } else {
    printf("The matrix is not a sparse matrix.\n");
  }
}

int main() {
  int rows, cols;

  // Input number of rows and columns
  printf("Enter number of rows: ");
  scanf("%d", &rows);
  printf("Enter number of columns: ");
  scanf("%d", &cols);

  int matrix[rows][cols];

  // Input matrix elements
  inputMatrix(rows, cols, matrix);

  // Check if the matrix is sparse
  int result = isSparseMatrix(rows, cols, matrix);

  // Display the result
  displayResult(result);

  return 0;
}
