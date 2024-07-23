/*
With the knowledge of modularization, function definition, function call etc.,
Write a function CornerSum which takes as a parameter, no. of rows and no. of
columns of a matrix and returns the sum of the elements in the four corners of the
matrix. Write a main function to test the function.
*/

#include <stdio.h>

// Function to calculate the sum of corner elements of a matrix
int CornerSum(int rows, int cols, int matrix[rows][cols]) {
   if (rows < 2 || cols < 2) {
      // For a matrix with less than 2 rows or columns, corners are not well-defined
      return 0;
   }
    
   int sum = 0;
   sum += matrix[0][0];           // Top-left corner
   sum += matrix[0][cols - 1];    // Top-right corner
   sum += matrix[rows - 1][0];    // Bottom-left corner
   sum += matrix[rows - 1][cols - 1]; // Bottom-right corner
    
   return sum;
}

int main() {

   int rows, cols;
    
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
    
   printf("Enter the number of columns: ");
   scanf("%d", &cols);
    
   int matrix[rows][cols];
    
   printf("Enter the elements of the matrix:\n");
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
    
   int sum = CornerSum(rows, cols, matrix);
    
   printf("The sum of the corner elements is: %d\n", sum);
    
   return 0;
   
}

