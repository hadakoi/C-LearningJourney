/*
With the knowledge of 2D arrays
To interchange the primary and secondary diagonal elements in the given Matrix.
*/

#include <stdio.h>

int main() {

   int n;

   printf("Enter the size of the matrix (n x n): ");
   scanf("%d", &n);

   int matrix[n][n];

   printf("Enter the elements of the matrix:\n");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }

   // Interchange primary and secondary diagonal elements
   for (int i = 0; i < n; i++) {
      int temp = matrix[i][i];
      matrix[i][i] = matrix[i][n - i - 1];
      matrix[i][n - i - 1] = temp;
   }

   printf("Modified matrix:\n");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }

   return 0;

}
