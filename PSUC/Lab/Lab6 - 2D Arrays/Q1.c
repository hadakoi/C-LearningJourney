/*
With the knowledge of 2D arrays
Find whether a given matrix is symmetric or not.
*/

#include <stdio.h>

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

    // Check for symmetry
    int symmetric = 1; // Assume the matrix is symmetric initially
    for (int i = 0; i < n && symmetric; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0; // Not symmetric
                break;
            }
        }
    }

    if (symmetric == 1) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
   
}
