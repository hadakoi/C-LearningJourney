/*
With the knowledge of 2D arrays
Find the trace and norm of a given square matrix. [Hint: Trace= sum of principal diagonal elements. Norm= SQRT (sum of squares of the individual elements of an array)]
*/

#include <stdio.h>
#include <math.h> // For sqrt function

int main() {

   int n;
   printf("Enter the size of the matrix (n x n): ");
   scanf("%d", &n);

   int matrix[n][n];
    
   // Input the matrix
   printf("Enter the elements of the matrix:\n");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }

   // Calculate the trace
   int trace = 0;
   for (int i = 0; i < n; i++) {
      trace += matrix[i][i];
   }

   // Calculate the norm
   float norm = 0.0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         norm += matrix[i][j] * matrix[i][j];
      }
   }

   norm = sqrtf(norm);

   printf("Trace of the matrix: %d\n", trace);
   printf("Norm of the matrix: %f\n", norm);

   return 0;

}
