#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int** createMatrix(int rows, int cols);  // Function to create a new dynamically allocated matrix
int** readMatrix(int rows, int cols);    // Function to read matrix elements and return a dynamically allocated matrix
void displayMatrix(int **matrix, int rows, int cols);  // Function to display a matrix
int** multiplyMatrices(int **matrix1, int **matrix2, int row1, int col1, int row2, int col2); // Multiply two matrices and return result

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

  // Read elements of the first matrix
  printf("Enter elements of the first matrix:\n");
  // The line below declares `matrix1` as a pointer to a dynamically allocated 2D matrix.
  // `readMatrix(row1, col1)` dynamically creates a 2D array using pointers and returns it.
  int **matrix1 = readMatrix(row1, col1);  

  // Read elements of the second matrix
  printf("Enter elements of the second matrix:\n");
  // Similarly, `matrix2` is declared as a pointer to a 2D matrix.
  int **matrix2 = readMatrix(row2, col2);  

  // Multiply matrices and store the result in a new matrix
  // `result` is also a double pointer pointing to the dynamically allocated result matrix.
  int **result = multiplyMatrices(matrix1, matrix2, row1, col1, row2, col2);

  // Display the matrices
  printf("First matrix:\n");
  displayMatrix(matrix1, row1, col1);

  printf("Second matrix:\n");
  displayMatrix(matrix2, row2, col2);

  printf("Product of the matrices:\n");
  displayMatrix(result, row1, col2);

  // Free dynamically allocated memory for all matrices
  for (int i = 0; i < row1; i++) free(matrix1[i]);  // Free memory for each row in matrix1
  for (int i = 0; i < row2; i++) free(matrix2[i]);  // Free memory for each row in matrix2
  for (int i = 0; i < row1; i++) free(result[i]);   // Free memory for each row in result

  free(matrix1);  // Free memory for the pointers to rows in matrix1
  free(matrix2);  // Free memory for the pointers to rows in matrix2
  free(result);   // Free memory for the pointers to rows in result

  return 0;
}

// Function to create a new dynamically allocated matrix
// This function returns a double pointer (int**) pointing to a 2D array (matrix).
int** createMatrix(int rows, int cols) {
  int **matrix = (int **)calloc(rows, sizeof(int *));  // Allocate memory for row pointers (array of pointers)
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)calloc(cols, sizeof(int));    // Allocate memory for each row (an int array)
  }
  // Here, we are returning a pointer to a dynamically allocated 2D array (matrix).
  return matrix;  // Return the pointer to the matrix
}

// Function to read matrix elements and return a dynamically allocated matrix
// We are passing rows and columns, and this function will return a double pointer to a matrix.
int** readMatrix(int rows, int cols) {
  int **matrix = createMatrix(rows, cols);  // Dynamically create a matrix (2D array)
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("Enter element at (%d, %d): ", i + 1, j + 1);
      // Here we dereference the pointer to access matrix elements.
      scanf("%d", &matrix[i][j]);  // Store input into matrix using array dereferencing
    }
  }
  // Return the pointer to the dynamically allocated matrix (int **matrix).
  return matrix;
}

// Function to display matrix elements
// `matrix` is a double pointer, which means we are passing a 2D array (matrix).
void displayMatrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      // Dereference the double pointer to access matrix elements
      printf("%d ", matrix[i][j]);  // Access element using array dereferencing
    }
    printf("\n");
  }
}

// Function to multiply two matrices and return the result in a newly allocated matrix
// This function takes two double pointers (`matrix1` and `matrix2`), which are pointers to 2D arrays.
int** multiplyMatrices(int **matrix1, int **matrix2, int row1, int col1, int row2, int col2) {
  // Create a new matrix for the result using dynamic memory allocation
  // This matrix will be a 2D array, and `result` is a double pointer to that matrix.
  int **result = createMatrix(row1, col2);

  // Initialize result matrix to 0
  for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col2; j++) {
      result[i][j] = 0;  // Initialize each element of the result matrix
    }
  }

  // Perform matrix multiplication
  for (int i = 0; i < row1; i++) {
   for (int j = 0; j < col2; j++) {
      for (int k = 0; k < col1; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];  // Calculate the sum of products
      }
    }
  }

  // Return the pointer to the result matrix, which is dynamically allocated.
  return result;
}

