/*
Implement a C program to read, display and to find the product of two matrices using functions with suitable parameters.
Check for the compatibility of the input matrices before multiplication.
*/

#include <stdio.h>

// Function to input a matrix
void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
  printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

// Function to display a matrix
void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
  printf("Matrix (%dx%d):\n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to multiply two matrices
int multiplyMatrices(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int product[rows1][cols2]) {
  // Check for compatibility: cols1 should be equal to rows2
  if (cols1 != rows2) {
    printf("Matrices are not compatible for multiplication.\n");
    return 0;  // Return 0 indicating incompatible matrices
  }

  // Multiply the matrices
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols2; j++) {
      product[i][j] = 0;  // Initialize product matrix
      for (int k = 0; k < cols1; k++) {
        product[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  return 1;  // Return 1 indicating successful multiplication
}

int main() {
  int rows1, cols1, rows2, cols2;

  // Input dimensions of the first matrix
  printf("Enter number of rows and columns for first matrix: ");
  scanf("%d %d", &rows1, &cols1);

  int matrix1[rows1][cols1];

  // Input elements of the first matrix
  inputMatrix(rows1, cols1, matrix1);

  // Input dimensions of the second matrix
  printf("Enter number of rows and columns for second matrix: ");
  scanf("%d %d", &rows2, &cols2);

  int matrix2[rows2][cols2];

  // Input elements of the second matrix
  inputMatrix(rows2, cols2, matrix2);

  // Display the input matrices
  printf("First ");
  displayMatrix(rows1, cols1, matrix1);
  printf("Second ");
  displayMatrix(rows2, cols2, matrix2);

  // Resultant matrix for the product
  int product[rows1][cols2];

  // Multiply matrices and check for compatibility
  if (multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, product)) {
    // Display the product matrix if multiplication is successful
    printf("Product ");
    displayMatrix(rows1, cols2, product);
  }

  return 0;
}
