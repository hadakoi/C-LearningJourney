#include <stdio.h>

int main() {

   int i, j, m, n;

   printf("Enter dimensions for the matrices (rows and columns): ");
   scanf("%d %d", &m, &n);

   int a[m][n], b[m][n], sum[m][n];


   printf("Enter elements of the first matrix:\n");
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         printf("Element [%d][%d]: ", i, j);
         scanf("%d", &a[i][j]);
      }
   }

   printf("Enter elements of the second matrix:\n");
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         printf("Element [%d][%d]: ", i, j);
         scanf("%d", &b[i][j]);
      }
   }

   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         sum[i][j] = a[i][j] + b[i][j];
      }
   }

   printf("\nThe resultant matrix after addition is:\n");
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         printf("%d\t", sum[i][j]);
      }
      printf("\n");
   }

   return 0;

}
