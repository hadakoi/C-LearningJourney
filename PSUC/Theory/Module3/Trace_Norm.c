#include <stdio.h>
#include <math.h>

int main() {

   int i, j;
   int m, n;
   int trace = 0;
   double sum = 0.0, norm;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

   if (m != n) {
      printf("Matrix must be square to compute trace. Returning 0.\n");
      return 0;
   }

   int a[m][n];

   printf("Enter elements for the matrix:\n");
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         printf("Element [%d][%d]: ", i, j);
         scanf("%d", &a[i][j]);
      }
   }

   for (i = 0; i < m; i++) {
      trace += a[i][i];
   }

   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
         sum += a[i][j] * a[i][j];
      }
   }
   norm = sqrt(sum);

   printf("Trace of the matrix: %d\n", trace);
   printf("norm of the matrix: %.2f\n", norm);

   return 0;

}
