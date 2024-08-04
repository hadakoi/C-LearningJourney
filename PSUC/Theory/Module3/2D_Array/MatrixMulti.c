#include <stdio.h>

int main() {

   int i, j, k;
   int m1, n1, m2, n2;

   printf("Enter the number of rows and columns for the first matrix: ");
   scanf("%d %d", &m1, &n1);

   printf("Enter the number of rows and columns for the second matrix: ");
   scanf("%d %d", &m2, &n2);

   // Check if multiplication is possible columns of matrix1 = rows of matrix 2 
   if (n1 != m2) {
      printf("Matrix multiplication is not possible.\n");
      return 1;
   }

   int a[m1][n1], b[m2][n2], result[m1][n2];

   printf("Enter elements of the first matrix:\n");
   for (i = 0; i < m1; i++) {
      for (j = 0; j < n1; j++) {
         printf("Element [%d][%d]: ", i, j);
         scanf("%d", &a[i][j]);
      }
   }

   printf("Enter elements of the second matrix:\n");
   for (i = 0; i < m2; i++) {
      for (j = 0; j < n2; j++) {
         printf("Element [%d][%d]: ", i, j);
         scanf("%d", &b[i][j]);
      }
   }

   for (i = 0; i < m1; i++) {
      for (j = 0; j < n2; j++) {
         result[i][j] = 0;
         for (k = 0; k < n1; k++) {
               result[i][j] += a[i][k] * b[k][j];
         }
      }
   }

   printf("\nThe resulting matrix is:\n");
   for (i = 0; i < m1; i++) {
      for (j = 0; j < n2; j++) {
         printf("%d\t", result[i][j]);
      }
      printf("\n");
   }

   return 0;

}
