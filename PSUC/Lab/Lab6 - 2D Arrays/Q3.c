/*
With the knowledge of 2D arrays
Perform matrix multiplication.
*/

#include <stdio.h>

int main() {
   
   int row1, col1, row2, col2;
    
   
   printf("Enter rows and columns for the first matrix: ");
   scanf("%d %d", &row1, &col1);

   
   printf("Enter rows and columns for the second matrix: ");
   scanf("%d %d", &row2, &col2);

   // Check if the matrices can be multiplied
   if (col1 != row2) {
      printf("Error! Column of the first matrix is not equal to row of the second matrix.\n");
      return -1;
   }

   
   int matrix1[row1][col1];
   int matrix2[row2][col2];
   int result[row1][col2];

   printf("Enter elements of the first matrix:\n");
   for (int i = 0; i < row1; i++) {
      for (int j = 0; j < col1; j++) {
         scanf("%d", &matrix1[i][j]);
      }
   }

   printf("Enter elements of the second matrix:\n");
   for (int i = 0; i < row2; i++) {
      for (int j = 0; j < col2; j++) {
         scanf("%d", &matrix2[i][j]);
      }
   }

   
   for (int i = 0; i < row1; i++) {
      for (int j = 0; j < col2; j++) {
         result[i][j] = 0;
      }
   }

   // Perform matrix multiplication
   for (int i = 0; i < row1; i++) {
      for (int j = 0; j < col2; j++) {
         for (int k = 0; k < col1; k++) {
               result[i][j] += matrix1[i][k] * matrix2[k][j];
         }
      }
   }

   printf("Resultant matrix:\n");
   for (int i = 0; i < row1; i++) {
      for (int j = 0; j < col2; j++) {
         printf("%d ", result[i][j]);
      }
      printf("\n");
   }

   return 0;

}
