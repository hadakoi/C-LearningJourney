/*
Implement a C program to read, display and to find the product of two matrices using functions with suitable parameters.
Note that the matrices should be created using dynamic memory allocation functions and the elements are accessed 
using array dereferencing.
*/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void readMatrix(int **matrix, int rows, int cols);
void displayMatrix(int **matrix, int rows, int cols);
void multiplyMatrices(int **matrix1, int **matrix2, int **result, int row1, int col1, int row2, int col2);

int main() {
  int row1, col1, row2, col2;

  // Read dimensions of the first matrix
  printf("Enter number of rows and columns for the first matrix: ");
  scanf("%d %d", &row1, &col1);

  // Read dimensions of the second matrix
  printf("Enter number of rows and columns for the second matrix: ");
  scanf("%d %d", &row2, &col2);

  // Check if matrix multiplication is possible
  if (col1 != row2) {
    printf("Error: Number of columns in first matrix must be equal to number of rows in second matrix.\n");
    return 1;
  }

  // Allocate memory for the matrices
  int **matrix1 = (int **)calloc(row1, sizeof(int *));
  for (int i = 0; i < row1; i++)
    matrix1[i] = (int *)calloc(col1, sizeof(int));

  int **matrix2 = (int **)calloc(row2, sizeof(int *));
  for (int i = 0; i < row2; i++)
    matrix2[i] = (int *)calloc(col2, sizeof(int));

  int **result = (int **)calloc(row1, sizeof(int *));
  for (int i = 0; i < row1; i++)
    result[i] = (int *)calloc(col2, sizeof(int));

  // Read elements of the matrices
  printf("Enter elements of the first matrix:\n");
  readMatrix(matrix1, row1, col1);
  printf("Enter elements of the second matrix:\n");
  readMatrix(matrix2, row2, col2);

  // Multiply matrices
  multiplyMatrices(matrix1, matrix2, result, row1, col1, row2, col2);

  // Display the matrices
  printf("First matrix:\n");
  displayMatrix(matrix1, row1, col1);
  printf("Second matrix:\n");
  displayMatrix(matrix2, row2, col2);
  printf("Product of the matrices:\n");
  displayMatrix(result, row1, col2);

  // Free dynamically allocated memory
  for (int i = 0; i < row1; i++)
    free(matrix1[i]);
  for (int i = 0; i < row2; i++)
    free(matrix2[i]);
  for (int i = 0; i < row1; i++)
    free(result[i]);

  free(matrix1);
  free(matrix2);
  free(result);

  return 0;
}

// Function to read matrix elements
void readMatrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Enter element at (%d, %d): ", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);  // Access element using array dereferencing
    }
  }
}

// Function to display matrix elements
void displayMatrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);  // Access element using array dereferencing
    }
  printf("\n");
  }
}

// Function to multiply two matrices
void multiplyMatrices(int **matrix1, int **matrix2, int **result, int row1, int col1, int row2, int col2) {
    // Initialize result matrix to 0
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];  // Access elements using array dereferencing
            }
        }
    }
}
